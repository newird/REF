from cpp_parser import *
from tree_sitter import Language, Parser, Query
import tree_sitter_cpp

CPP_LANGUAGE = Language(tree_sitter_cpp.language(), "CPP")
cpp_source_code = """
#include <iostream>

int f(){};
int main() {
    std::cout << "Hello, World!" << std::endl;
    f();
    return 0;
}
"""

# Parse the source code
tree = parse_from_src(cpp_source_code)

# Define and run the query
query_call = """
(call_expression
    function: (identifier) @function-name
    arguments: (argument_list) @arguments)
"""
query_assign = """
()
"""
query = CPP_LANGUAGE.query(query_call)
captures = query.captures(tree.root_node)

for capture, _ in captures:
    print(f'Function call to: {capture.text.decode("utf8")}')
