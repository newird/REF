import torch
from torch.nn.functional import cosine_similarity
from transformers import AutoTokenizer, AutoModel
import argparse
import os

import json
import numpy as np
from collections import defaultdict


def get_trace_path(source_file):
    """根据源代码文件路径获取对应的跟踪文件路径"""
    # 假设源文件格式是 folder/id.c，跟踪文件格式是 trace/id.txt
    base_name = os.path.basename(source_file)  # 获取文件名 (例如 "1.c")
    file_id = os.path.splitext(base_name)[0]  # 获取文件ID (例如 "1")
    trace_path = os.path.join("trace", f"{file_id}.txt")  # 构建跟踪文件路径

    return trace_path


def adaptar(wrong_file, correct_file, bert=True):
    """
    适配函数，转换源代码文件路径为跟踪文件路径，并调用比较函数

    参数:
    wrong_file : 错误答案源代码文件路径 (例如 "wronganswer/1.c")
    correct_file: 正确答案源代码文件路径 (例如 "correctanswer/2.c")

    返回:
    错误源代码行到正确源代码行的映射字典
    """
    # 获取对应的跟踪文件路径
    wrong_trace = get_trace_path(wrong_file)
    correct_trace = get_trace_path(correct_file)
    if bert:
        return compare_bert(wrong_trace, correct_trace)
    else:
        return compare_naive(wrong_trace, correct_trace)


def read_file(file_path):
    with open(file_path, "r", encoding="utf-8") as file:
        return [line.strip() for line in file if line.strip()]


def parse_trace_line(line):
    """解析跟踪日志中的每一行"""
    try:
        return json.loads(line)
    except json.JSONDecodeError:
        return None


def read_trace_file(file_path):
    """读取跟踪文件并解析每一行"""
    trace_lines = []
    with open(file_path, "r", encoding="utf-8") as f:
        for line in f:
            parsed = parse_trace_line(line.strip())
            if parsed:
                trace_lines.append(parsed)
    return trace_lines


def group_by_source_line(trace_lines):
    """按源代码行分组执行信息"""
    line_groups = defaultdict(list)
    for trace in trace_lines:
        source_line = trace["line"]
        line_groups[source_line].append(trace)
    return line_groups


def create_line_fingerprint(traces):
    """为源代码行创建特征指纹"""
    # 提取所有可能的存储变量
    all_vars = set()
    for trace in traces:
        if "storage" in trace:
            all_vars.update(trace["storage"].keys())

    # 创建执行次数统计
    execution_count = len(traces)

    # 创建变量状态变化统计
    var_stats = {}
    for var in all_vars:
        values = []
        for trace in traces:
            if "storage" in trace and var in trace["storage"]:
                try:
                    values.append(float(trace["storage"][var]))
                except ValueError:
                    # 如果不能转换为数字，使用哈希值
                    values.append(hash(trace["storage"][var]) % 1000)

        if values:
            var_stats[var] = {
                "min": min(values),
                "max": max(values),
                "mean": sum(values) / len(values),
                "changes": len(set(values)),
            }

    return {
        "execution_count": execution_count,
        "source": traces[0]["src"],
        "var_stats": var_stats,
    }


def vectorize_fingerprint(fingerprint, all_features):
    """将行指纹转换为特征向量"""
    vector = []

    # 执行次数特征
    vector.append(fingerprint["execution_count"])

    # 源代码长度特征
    vector.append(len(fingerprint["source"]))

    # 变量状态统计特征
    for var in all_features:
        if var in fingerprint["var_stats"]:
            stats = fingerprint["var_stats"][var]
            vector.extend([stats["min"], stats["max"], stats["mean"], stats["changes"]])
        else:
            vector.extend([0, 0, 0, 0])

    return vector


def calculate_line_similarities(trace_file_path):
    """计算源代码行之间的相似度"""
    # 读取和分组跟踪信息
    traces = read_trace_file(trace_file_path)
    line_groups = group_by_source_line(traces)

    # 为每行创建指纹
    line_fingerprints = {}
    for line_num, traces in line_groups.items():
        line_fingerprints[line_num] = create_line_fingerprint(traces)

    # 提取所有变量特征
    all_vars = set()
    for fingerprint in line_fingerprints.values():
        all_vars.update(fingerprint["var_stats"].keys())

    # 创建特征向量
    line_vectors = {}
    for line_num, fingerprint in line_fingerprints.items():
        line_vectors[line_num] = vectorize_fingerprint(fingerprint, all_vars)

    # 计算相似度矩阵
    line_nums = list(line_vectors.keys())
    vectors = [line_vectors[line] for line in line_nums]

    if vectors:
        similarity_matrix = cosine_similarity(vectors)

        # 输出每行与其他行的相似度
        print("源代码行相似度分析:")
        print("=" * 50)

        for i, line_i in enumerate(line_nums):
            print(f"\n行 {line_i} ('{line_fingerprints[line_i]['source']}')")
            print("-" * 50)

            # 找出相似度最高的其他行（排除自身）
            similarities = []
            for j, line_j in enumerate(line_nums):
                if i != j:  # 排除自身
                    similarities.append((line_j, similarity_matrix[i][j]))

            # 按相似度降序排序
            similarities.sort(key=lambda x: x[1], reverse=True)

            # 输出相似度最高的5行（或更少）
            for line_j, sim in similarities[:5]:
                print(
                    f"  与行 {line_j} ('{line_fingerprints[line_j]['source']}') 相似度: {sim:.4f}"
                )

    return line_fingerprints, similarity_matrix if vectors else None


def compare_naive(file_path1, file_path2):
    traces1 = read_file(file_path1)
    traces2 = read_file(file_path2)

    line_groups1 = group_by_source_line(traces1)
    line_groups2 = group_by_source_line(traces2)

    line_fingerprints1 = {}
    for line_num, traces in line_groups1.items():
        line_fingerprints1[line_num] = create_line_fingerprint(traces)

    line_fingerprints2 = {}
    for line_num, traces in line_groups2.items():
        line_fingerprints2[line_num] = create_line_fingerprint(traces)

    # 提取所有变量特征
    all_vars = set()
    for fingerprint in list(line_fingerprints1.values()) + list(
        line_fingerprints2.values()
    ):
        all_vars.update(fingerprint["var_stats"].keys())

    # 创建特征向量
    line_vectors1 = {}
    for line_num, fingerprint in line_fingerprints1.items():
        line_vectors1[line_num] = vectorize_fingerprint(fingerprint, all_vars)

    line_vectors2 = {}
    for line_num, fingerprint in line_fingerprints2.items():
        line_vectors2[line_num] = vectorize_fingerprint(fingerprint, all_vars)

    # 计算文件1中每行与文件2中每行的相似度
    print("两个文件之间的行相似度分析:")
    print("=" * 60)

    for line1, vector1 in line_vectors1.items():
        print(f"\n文件1中的行 {line1} ('{line_fingerprints1[line1]['source']}')")
        print("-" * 60)

        similarities = []
        for line2, vector2 in line_vectors2.items():
            # 计算两个向量之间的余弦相似度
            similarity = cosine_similarity([vector1], [vector2])[0][0]
            similarities.append((line2, similarity))

        # 按相似度降序排序
        similarities.sort(key=lambda x: x[1], reverse=True)

        # 输出相似度最高的行
        for line2, sim in similarities[:3]:
            print(
                f"  与文件2中的行 {line2} ('{line_fingerprints2[line2]['source']}') 相似度: {sim:.4f}"
            )

    return line_fingerprints1, line_fingerprints2


def read_trace(file_path):
    """读取跟踪文件并提取源代码行和行号"""
    trace_lines = []
    line_to_source = {}

    with open(file_path, "r", encoding="utf-8") as file:
        for line in file:
            try:
                trace_data = json.loads(line.strip())
                if "line" in trace_data and "src" in trace_data:
                    line_num = trace_data["line"]
                    source_code = trace_data["src"]
                    if line_num not in line_to_source:
                        line_to_source[line_num] = source_code
                        trace_lines.append((line_num, source_code))
            except json.JSONDecodeError:
                continue

    return trace_lines, line_to_source


def compare_bert(wrong_trace, correct_trace):
    """计算错误跟踪和正确跟踪之间的代码相似度，并创建映射字典"""
    tokenizer = AutoTokenizer.from_pretrained("microsoft/codebert-base")
    model = AutoModel.from_pretrained("microsoft/codebert-base")

    if not os.path.exists(wrong_trace) or not os.path.exists(correct_trace):
        return None
    wrong_lines, wrong_dict = read_trace(wrong_trace)
    correct_lines, correct_dict = read_trace(correct_trace)

    # 用于存储结果的字典
    wrong_to_correct_mapping = {}

    with torch.no_grad():
        # 为错误文件中的每一行获取嵌入
        wrong_embeddings = {}
        for line_num, source in wrong_lines:
            inputs = tokenizer(
                source, padding=True, truncation=True, return_tensors="pt"
            )
            outputs = model(**inputs)
            embedding = outputs.last_hidden_state.mean(dim=1).squeeze()
            wrong_embeddings[line_num] = embedding

        # 为正确文件中的每一行获取嵌入
        correct_embeddings = {}
        for line_num, source in correct_lines:
            inputs = tokenizer(
                source, padding=True, truncation=True, return_tensors="pt"
            )
            outputs = model(**inputs)
            embedding = outputs.last_hidden_state.mean(dim=1).squeeze()
            correct_embeddings[line_num] = embedding

    for wrong_line, wrong_emb in wrong_embeddings.items():
        max_sim = -1
        best_match = None

        for correct_line, correct_emb in correct_embeddings.items():
            sim = cosine_similarity(
                wrong_emb.unsqueeze(0), correct_emb.unsqueeze(0)
            ).item()
            if sim > max_sim:
                max_sim = sim
                best_match = correct_line

        if best_match:
            wrong_to_correct_mapping[wrong_line] = {
                "correct_line": best_match,
                "wrong_src": wrong_dict[wrong_line],
                "correct_src": correct_dict[best_match],
                "similarity": max_sim,
            }

    return wrong_to_correct_mapping


def display_mapping(mapping):
    """显示映射结果"""
    print("\n源代码行映射结果:")
    print("=" * 80)

    # 按相似度降序排序
    sorted_items = sorted(
        mapping.items(), key=lambda x: x[1]["similarity"], reverse=True
    )

    for wrong_line, match_info in sorted_items:
        print(f"Wrong line {wrong_line}: '{match_info['wrong_src']}'")
        print(
            f"  → Correct line {match_info['correct_line']}: '{match_info['correct_src']}'"
        )
        print(f"  Similarity: {match_info['similarity']:.4f}")
        print("-" * 80)


def main():
    wrong_trace_file = "wrong_trace.txt"
    correct_trace_file = "correct_trace.txt"

    mapping = compare_bert(wrong_trace_file, correct_trace_file)
    display_mapping(mapping)


if __name__ == "__main__":
    main()
