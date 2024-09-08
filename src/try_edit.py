import tree_sitter_python
from tree_sitter import Language, Parser
from treeutil import TreeUtil

PY_LANGUAGE = Language(tree_sitter_python.language(), "python")

parser = Parser()
parser.set_language(PY_LANGUAGE)

# parsing a string of code
tree = parser.parse(
    bytes(
        """
def foo():
    if bar:
        baz()
""",
        "utf8",
    )
)
src = bytes(
    """
def foo():
    if bar:
        baz()
""",
    "utf8",
)
# new_src = src[:5] + src[5 : 5 + 2].upper() + src[5 + 2 :]
new_src = src

root = tree.root_node
start_point = root.start_point
start_byte = root.start_byte
end_byte = root.end_byte
end_point = root.end_point

treeutil = TreeUtil()
treeutil.print_tree(tree.root_node)

tree.edit(
    start_byte=start_byte,
    old_end_byte=end_byte,
    new_end_byte=5 + 2,
    start_point=start_point,
    old_end_point=end_point,
    new_end_point=(0, 5 + 2),
)
new_tree = parser.parse(new_src, tree)
treeutil.print_tree(new_tree.root_node)
# inspecting the changes
for changed_range in tree.changed_ranges(new_tree):
    print("Changed range:")
    print(f"  Start point {changed_range.start_point}")
    print(f"  Start byte {changed_range.start_byte}")
    print(f"  End point {changed_range.end_point}")
    print(f"  End byte {changed_range.end_byte}")
