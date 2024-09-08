# from cpp_parser import *
from sys import exception
from tree_sitter import Language, Parser, Node, Query

# import tree_sitter_cpp
from typing import List, Optional, Union, Dict, Tuple


class QQ:
    def collect_matches(
        self,
        matches: List[Tuple[int, Dict[str, Union[Node, List[Node]]]]],
    ) -> List[Tuple[int, List[Tuple[str, Union[str, List[str]]]]]]:
        return [(m[0], self.format_captures(m[1])) for m in matches]

    def format_captures(
        self, captures: Dict[str, Union[Node, List[Node]]]
    ) -> List[Tuple[str, Union[str, List[str]]]]:
        return [
            (name, self.format_capture(capture)) for name, capture in captures.items()
        ]

    def format_capture(self, capture: Union[Node, List[Node]]) -> Union[str, List[str]]:
        return (
            [n.text.decode("utf-8") for n in capture]
            if isinstance(capture, List)
            else capture.text.decode("utf-8")
        )

    def find_matches(self, tree, query):
        matches = query.matches(tree.root_node)
        print(matches)
        matches = self.collect_matches(matches)
        return matches


from tree_sitter import Language, Parser
import tree_sitter_cpp
import tree_sitter_python
from cpp_parser import parse_file
import logging

logger = logging.getLogger(__name__)
logging.basicConfig(filename="debug.log", encoding="utf-8", level=logging.INFO)


def print_tree(node, indent=0):
    print(" " * indent + f"{node.type} ")
    for child in node.children:
        print_tree(child, indent + 2)


def main():
    tree = parse_file("./sum.cpp")
    # Prepare a query
    # print_tree(tree.root_node)
    qq = QQ()
    LANGUAGE = Language(tree_sitter_python.language(), "cpp")
    try:
        query = LANGUAGE.query("(expression_statement (identifier) (identifier))")
        matches = qq.find_matches(tree, query)
        print(matches)
    except Exception as e:
        print(e)


if __name__ == "__main__":
    main()
