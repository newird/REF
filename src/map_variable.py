from cpp_parser import *
import unittest
import logging

logger = logging.getLogger(__name__)
logging.basicConfig(filename="debug.log", encoding="utf-8", level=logging.INFO)


def Map(correct_file, incorrect_file):
    correct_ast = parse_file(correct_file)
    incorrect_ast = parse_file(incorrect_file)
    c_input, c_variable, c_output = get_variable(correct_ast.root_node)
    i_input, i_variable, i_output = get_variable(incorrect_ast.root_node)

    one_to_one = {}
    if len(c_input) == len(i_input):
        for c, i in zip(c_input, i_input):
            one_to_one[c] = i
    else:
        logger.error("Input variable count mismatch")
    if len(c_output) == len(i_output):
        for c, i in zip(c_output, i_output):
            one_to_one[c] = i
    else:
        logger.error("Output variable count mismatch")

    incorrect_depend_graph = construct_dependency_graph(incorrect_ast.root_node)
    correct_depend_graph = construct_dependency_graph(correct_ast.root_node)

    for k, v in one_to_one.items():
        print(f"{k} -> {v}")
    # Map dependencies based on constructed dependency graphs
    reverse_correct_graph = {}
    for var, deps in correct_depend_graph.items():
        reverse_correct_graph[tuple(sorted(deps))] = var
    # while one_to_one len changed
    one_to_one_len = -1
    while one_to_one_len != len(one_to_one):
        one_to_one_len = len(one_to_one)
        for i_var, i_deps in incorrect_depend_graph.items():
            logger.info(f"Mapping dependencies for {i_var}")
            logger.info(f"Dependencies: {i_deps}")
            translated_deps = tuple(sorted(one_to_one.get(dep, dep) for dep in i_deps))
            logger.info(f"Translated dependencies: {translated_deps}")
            if translated_deps in reverse_correct_graph:
                one_to_one[i_var] = reverse_correct_graph[translated_deps]

    return one_to_one


def change_variable_name(ast, src, old_var, new_var):
    cursor = ast.walk()

    def recursive_rename(cursor, src, old_var, new_var, diff):
        while True:
            # Process the current node
            if cursor.node.type == "identifier" and cursor.node.text == old_var:
                logger.info(f"Renaming {old_var} to {new_var}")
                start_byte = cursor.node.start_byte + diff

                # Adjust for any previous changes
                new_var_decoded = new_var.decode("utf-8")
                old_var_length = len(old_var)
                new_var_length = len(new_var_decoded)

                # Modify the source string
                src = (
                    src[:start_byte]
                    + new_var_decoded
                    + src[start_byte + old_var_length :]
                )

                # Update diff to account for length changes
                diff += new_var_length - old_var_length
                # print(start_byte, src[start_byte : start_byte + old_var_length])
                # print(f"change {old_var} to {new_var_decoded}")

            # Recurse into child nodes
            if cursor.goto_first_child():
                src, diff = recursive_rename(cursor, src, old_var, new_var, diff)
                cursor.goto_parent()

            if not cursor.goto_next_sibling():
                break

        return src, diff

    # Initial call to recursive_rename with initial diff as 0
    src, _ = recursive_rename(cursor, src, old_var, new_var, 0)
    return src


def hange_variable_name(ast, src, old_var, new_var):
    """
    This function traverses the AST using a cursor and updates identifier nodes if they exist in the mapping.

    Args:
    ast (AST): The root of the AST to be modified.
    ma (dict): The mapping from incorrect to correct variable names.
    """
    cursor = ast.walk()

    def recursive_rename(cursor, ast, src, old_var, new_var, diff):
        # Check if the current node is an identifier and if it needs to be renamed
        if cursor.node.type == "identifier" and cursor.node.text == old_var:
            # Log the change for debugging purposes
            logger.info(f"Renaming {old_var} to {new_var}")
            # Perform the renaming; you might need to adjust this depending on how your AST library handles changes
            # If the library allows, modify the node directly, otherwise collect changes to be applied later
            start_byte = cursor.node.start_byte + diff

            new_var = new_var.decode("utf-8")
            diff += len(new_var) - len(old_var)
            print(start_byte, src[start_byte : start_byte + len(old_var)])
            print(f"change {old_var} to {new_var}")

            src = src[:start_byte] + new_var + src[start_byte + len(old_var) :]
            print(src)

        # Visit children of the current node
        if cursor.goto_first_child():
            while True:
                recursive_rename(cursor, ast, src, old_var, new_var, diff)
                if not cursor.goto_next_sibling():
                    break
            cursor.goto_parent()  # Return to the parent node after finishing the children

        return src

    return recursive_rename(cursor, ast, src, old_var, new_var, 0)


def rename_var_in_file(correct_file, incorrect_file):
    ma = Map(correct_file, incorrect_file)
    with open(correct_file, "r", encoding="utf-8") as f:
        src = f.read()
    correct_ast = parse_file(correct_file)
    for k, v in ma.items():
        src = change_variable_name(correct_ast, src, k, v)
        correct_ast = parse_from_src(src)
    return src


def main():
    if len(sys.argv) != 3:
        print("Usage: python map_variable.py <correct_file> <incorrect_file>")
        sys.exit(1)
    correct_file = sys.argv[1]
    incorrect_file = sys.argv[2]
    if not os.path.exists(correct_file):
        logger.error(f"File {correct_file} does not exist.")
        sys.exit(1)
    if not os.path.exists(incorrect_file):
        logger.error(f"File {incorrect_file} does not exist.")
        sys.exit(1)
    ma = Map(correct_file, incorrect_file)
    with open(correct_file, "r", encoding="utf-8") as f:
        src = f.read()
    print(src)
    correct_ast = parse_file(correct_file)

    for k, v in ma.items():
        src = change_variable_name(correct_ast, src, k, v)
        correct_ast = parse_from_src(src)

    print(src)


if __name__ == "__main__":
    main()


class TestMap(unittest.TestCase):
    def test_map(self):
        ma = Map("test/a.cpp", "test/b.cpp")
        self.assertEqual(b"longera", ma[b"a"])
        self.assertEqual(b"notb", ma[b"b"])
        self.assertEqual(b"thisisc", ma[b"c"])
        self.assertEqual(b"de", ma[b"d"])
        self.assertEqual(b"whichon", ma[b"e"])
        self.assertEqual(b"fun", ma[b"f"])
        self.assertEqual(b"ggg", ma[b"g"])
