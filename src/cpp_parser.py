import tree_sitter_cpp
from tree_sitter import Language, Parser
import sys
import os
import logging
from collections import OrderedDict
import unittest

# write to log file
logger = logging.getLogger(__name__)
logging.basicConfig(filename="debug.log", encoding="utf-8", level=logging.INFO)


def parse_file(file_path):
    try:
        with open(file_path, "r") as file:
            source_code = file.read()
        tree = parse_from_src(source_code)
        return tree
    except Exception as e:
        logger.error(f"Error reading file {file_path}: {e}")


def parse_from_src(src):
    parser = Parser()
    cpp_language = Language(tree_sitter_cpp.language(), "cpp")
    parser.set_language(cpp_language)
    tree = parser.parse(bytes(src, "utf8"))
    return tree

    # extract type and identifier from declaration node
    # maybe with multiable identifier
    # eg int a, b, c;
    # return a map


def extract_type_and_identifier(declaration_node):
    type_text = ""
    identifier_texts = []
    for child in declaration_node.children:
        if child.type in ["primitive_type", "type_identifier", "template_type"]:
            type_text = child.text
        # init with value eg int a = 1;
        elif child.type == "init_declarator" and child.children[0].type == "identifier":
            identifier_texts.append(child.children[0].text)
        # init without value eg int a;
        elif child.type == "identifier":
            identifier_texts.append(child.text)

    return {identifier_text: type_text for identifier_text in identifier_texts}


def is_input(node):
    return b"cin" in node.text


def is_output(node):
    return b"cout" in node.text


def is_scanf(node):
    text = node.children[0].text
    return b"scanf" in text


def is_printf(node):
    text = node.children[0].text
    return b"printf" in text


def inorder(node, input, variable, output):
    if node is None:
        print("node is None")
        return

    for node in node.children:
        inorder(node, input, variable, output)
        # if is binary expression
        if node.type == "binary_expression":
            # if is cin
            left = node.children[0]
            right = node.children[2]
            if is_input(left):
                input[right.text] = right.text
            elif is_output(node):
                output[right.text] = right.text

        elif node.type == "declaration":
            init_variable = extract_type_and_identifier(node)
            variable.update(init_variable)
        elif node.type == "call_expression":
            if is_scanf(node):
                for content in node.children[1].children:
                    for arg in content.children:
                        if arg.type == "identifier":
                            input[arg.text] = arg.text

            if is_printf(node):
                arguments = node.children[1]
                for arg in arguments.children:
                    if arg.type == "identifier":
                        output[arg.text] = arg.text


def construct_dependency_graph(root_node):
    graph = {}

    def get_identifier(node):
        if node.type == "identifier":
            yield node.text
        for child in node.children:
            yield from get_identifier(child)

    def dfs(node):
        if node is None:
            return
        for child in node.children:
            if child.type == "assignment_expression":
                left = child.children[0]
                right = child.children[2]

                if left.type == "identifier":
                    id = list(get_identifier(right))
                    if left.text not in graph:
                        graph[left.text] = []
                    graph[left.text] += id
            dfs(child)

    dfs(root_node)
    return graph


# read in variable
# print variable
# middle variable
# inorder traversal
def get_variable(root):
    input = OrderedDict()
    variable = OrderedDict()
    output = OrderedDict()

    inorder(root, input, variable, output)
    # q = []
    # q.append(root_node)
    # while q:
    #     c = q.pop(0)
    #     for node in c.children:
    #         # if is binary expression
    #         if node.type == "binary_expression":
    #             # if is cin
    #             left = node.children[0]
    #             right = node.children[2]
    #             if is_input(left):
    #                 input[str(right.text)] = right.text
    #             elif is_output(node):
    #                 output[str(right.text)] = right.text
    #
    #         elif node.type == "declaration":
    #             init_variable = extract_type_and_identifier(node)
    #             variable.update(init_variable)
    #         elif node.type == "call_expression":
    #             if is_scanf(node):
    #                 for content in node.children[1].children:
    #                     for arg in content.children:
    #                         if arg.type == "identifier":
    #                             input[str(arg.text)] = arg.text
    #
    #             if is_printf(node):
    #                 for content in node.children[1].children:
    #                     for arg in content.children:
    #                         if arg.type == "identifier":
    #                             input[str(arg.text)] = arg.text
    #         q.append(node)

    def check(candidate, normal):
        for key in candidate:
            if key in normal:
                candidate[key] = normal[key]
            else:
                del candidate[key]

    check(input, variable)
    check(output, variable)

    return input, variable, output


def main():
    if len(sys.argv) != 2:
        print("Usage: python cpp_parser.py <source_file>")
        sys.exit(1)
    file_path = sys.argv[1]
    if not os.path.exists(file_path):
        logger.error(f"File {file_path} does not exist.")
        sys.exit(1)
    tree = parse_file(file_path)
    root_node = tree.root_node
    logger.info(f"Root node type: {root_node.sexp()}")

    input, normal, output = get_variable(root_node)


if __name__ == "__main__":
    main()


# test
class TestCppParser(unittest.TestCase):
    def test_get_variable(self):
        src = """
#include <iostream>
using namespace std;
int main() {
    int a , b;
    cin >> a >> b;
    int c = a + b;
    int d = 4;
    cout << c <<endl;
    return 0;
}
        """

        parser = Parser()
        cpp_language = Language(tree_sitter_cpp.language(), "cpp")
        parser.set_language(cpp_language)
        tree = parser.parse(bytes(src, "utf8"))
        r, n, w = get_variable(tree.root_node)
        self.assertEqual(len(r), 2)
        self.assertEqual(len(n), 4)
        self.assertEqual(len(w), 1)

    def test_get_variable2(self):
        src = """
#include <iostream>

using namespace std;

int g = 3;
int f(){
  return 2;
}
int main() {
  int a ;
  cin >> a;
  int b = 4;
  int c = a + 1;
  int d ;
  int e = f();

  return 0;
}
"""
        parser = Parser()
        cpp_language = Language(tree_sitter_cpp.language(), "cpp")
        parser.set_language(cpp_language)
        tree = parser.parse(bytes(src, "utf8"))
        r, n, w = get_variable(tree.root_node)

        self.assertIn(b"a", r)
        self.assertIn(b"a", n)
        self.assertIn(b"b", n)
        self.assertIn(b"c", n)
        self.assertIn(b"d", n)
        self.assertIn(b"e", n)
        self.assertIn(b"g", n)

    def test_get_variable3(self):
        src = """

#include <iostream>

using namespace std;

int main() {
  int a ,b ,c ;
  scanf("%d" , &b) ;
  int d , e, f;
  scanf("%d %d %d" , &d , &e , &f) ;

  return 0;
}
    """
        parser = Parser()
        cpp_language = Language(tree_sitter_cpp.language(), "cpp")
        parser.set_language(cpp_language)
        tree = parser.parse(bytes(src, "utf8"))
        r, n, w = get_variable(tree.root_node)

        self.assertIn(b"b", r)
        self.assertIn(b"d", r)
        self.assertIn(b"e", r)
        self.assertIn(b"f", r)

    def test_construct_dependency_graph(self):
        src = """
#include<iostream>
using namespace std;

int main(){
    int a , b , c , d ,e,f,g;
    cin >> a >> b;
    c = a + b;
    d = b + c;
    e = c * d;
    f = a + e;
    g = f / d;
    return 0;
    
}
    """

        parser = Parser()
        cpp_language = Language(tree_sitter_cpp.language(), "cpp")
        parser.set_language(cpp_language)
        tree = parser.parse(bytes(src, "utf8"))
        graph = construct_dependency_graph(tree.root_node)
        self.assertEqual(graph[b"c"], [b"a", b"b"])
        self.assertEqual(graph[b"d"], [b"b", b"c"])
        self.assertEqual(graph[b"e"], [b"c", b"d"])
        self.assertEqual(graph[b"f"], [b"a", b"e"])
        self.assertEqual(graph[b"g"], [b"f", b"d"])
