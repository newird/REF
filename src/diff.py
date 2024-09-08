import difflib
from typing import List
from map_variable import rename_var_in_file


def _heuristic_replace_match(a_tokens: List[str], b_tokens: List[str]):
    diff_seqs = []
    a_len = len(a_tokens)
    b_len = len(b_tokens)
    delta_len = max(a_len - b_len, b_len - a_len)
    if a_len != b_len:
        head_ratio = difflib.SequenceMatcher(
            None, a_tokens[0], b_tokens[0]
        ).quick_ratio()
        tail_ratio = difflib.SequenceMatcher(
            None, a_tokens[-1], b_tokens[-1]
        ).quick_ratio()
        if head_ratio >= tail_ratio:
            if a_len > b_len:
                b_tokens += [""] * delta_len
            else:
                a_tokens += [""] * delta_len
        else:
            if a_len > b_len:
                b_tokens = [""] * delta_len + b_tokens
            else:
                a_tokens = [""] * delta_len + a_tokens
    assert len(a_tokens) == len(b_tokens)
    for at, bt in zip(a_tokens, b_tokens):
        if at == "":
            diff_seqs.append([at, bt, "insert"])
        elif bt == "":
            diff_seqs.append([at, bt, "delete"])
        else:
            diff_seqs.append([at, bt, "replace"])
    return diff_seqs


def construct_diff_sequence(a: List[str], b: List[str]) -> List[List[str]]:
    diff_seqs = []
    diff = difflib.SequenceMatcher(None, a, b)

    for op, a_i, a_j, b_i, b_j in diff.get_opcodes():
        a_tokens = a[a_i:a_j]
        b_tokens = b[b_i:b_j]
        if op == "delete":
            for at in a_tokens:
                diff_seqs.append([at, "", op])
        elif op == "insert":
            for bt in b_tokens:
                diff_seqs.append(["", bt, op])
        elif op == "equal":
            for at, bt in zip(a_tokens, b_tokens):
                diff_seqs.append([at, bt, op])
        else:
            # replace
            diff_seqs += _heuristic_replace_match(a_tokens, b_tokens)

    return diff_seqs


def read_from_file(file_path: str) -> List[str]:
    with open(file_path, "r") as f:
        return f.read().splitlines()


def compare_files(file_a: str, file_b: str) -> List[List[str]]:
    b = read_from_file(file_b)
    a = rename_var_in_file(file_a, file_b)
    a = a.splitlines()
    return construct_diff_sequence(a, b)


def is_input(a, b):
    if ("scanf" in a or "cin" in a) and ("scanf" in b or "cin" in b):
        return True
    else:
        return False


def is_output(a, b):
    if ("printf" in a or "cout" in a) and ("printf" in b or "cout" in b):
        return True
    else:
        return False


def is_macro(a: str, b: str) -> bool:
    if a.startswith("#") or b.startswith("#"):
        return True
    if "using" in a or "using" in b:
        return True
    else:
        return False


if __name__ == "__main__":
    import sys

    if len(sys.argv) != 3:
        print("Usage: python diff.py <correct_file> <incorrect_file>")
    diff_seqs = compare_files(sys.argv[1], sys.argv[2])
    for seq in diff_seqs:
        if is_input(seq[0], seq[1]):
            continue
        if is_output(seq[0], seq[1]):
            continue
        if is_macro(seq[0], seq[1]):
            continue
        if seq[2] != "equal":
            print(seq)
