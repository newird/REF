class TreeUtil:
    def print_tree(self, node, indent=0):
        text = str(node.text) if len(node.children) == 0 else ""
        print(" " * indent + f"{node.type} : {text} ")
        for child in node.children:
            self.print_tree(child, indent + 2)
