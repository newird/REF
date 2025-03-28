import difflib
from typing import List

from map_variable import rename_var_in_file
from trace_align import *


def _heuristic_replace_match(
    a_tokens: List[str],
    b_tokens: List[str],
    dynamic_align,
    similarity_threshold: float = 0.85,
):
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
            similarity = difflib.SequenceMatcher(None, at, bt).ratio()
            if similarity >= similarity_threshold:
                diff_seqs.append([at, bt, "equal"])
            elif dynamic_align and at in dynamic_align and dynamic_align[at] == bt:
                diff_seqs.append([at, bt, "equal"])
            else:
                diff_seqs.append([at, bt, "replace"])
    return diff_seqs


def construct_diff_sequence(
    a: List[str], b: List[str], dynamic_align
) -> List[List[str]]:
    diff_seqs = []
    static_align = difflib.SequenceMatcher(None, a, b)
    for op, a_i, a_j, b_i, b_j in static_align.get_opcodes():
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
            diff_seqs += _heuristic_replace_match(a_tokens, b_tokens, dynamic_align)

    return diff_seqs


def read_from_file(file_path: str) -> List[str]:
    with open(file_path, "r") as f:
        return f.read().splitlines()


def compare_files(file_a: str, file_b: str) -> List[List[str]]:
    with_rn = False
    with_dy = True
    dynamic_align = adaptar(sys.argv[1], sys.argv[2], with_dy)
    if with_rn:
        b = read_from_file(file_b)
        a = rename_var_in_file(file_a, file_b)
        a = a.splitlines()
    else:
        a = read_from_file(file_a)
        b = read_from_file(file_b)
    return construct_diff_sequence(a, b, dynamic_align)


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


def show_aligned(diff_seqs):
    pair = 0
    accurracy = 0
    for seq in diff_seqs:
        if is_input(seq[0], seq[1]):
            continue
        if is_output(seq[0], seq[1]):
            continue
        if is_macro(seq[0], seq[1]):
            continue
        if seq[2] == "equal":
            if not seq[0] and not seq[1]:
                continue
            if seq[0].strip() == "{" or seq[0].strip() == "}":
                continue
            dist = distance(seq[0], seq[1])
            similarity = 1 - dist / max(len(seq[0]), len(seq[1]))
            pair += 1
            accurracy += similarity
            print(seq[0] + " <-> " + seq[1])
    if pair == 0:
        print(0)
    else:
        print(str(accurracy / pair))


if __name__ == "__main__":
    import sys
    import time
    from Levenshtein import distance

    if len(sys.argv) != 3:
        print("Usage: python align.py <incorrect_file> <correct_file>")
    start = time.time()
    diff_seqs = compare_files(sys.argv[1], sys.argv[2])
    print(time.time() - start)
    show_aligned(diff_seqs)
