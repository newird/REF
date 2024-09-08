from scipy.linalg import cossin
import torch
from transformers import AutoModel
from numpy.linalg import norm


def align():
    cos_sim = lambda a, b: (a @ b.T) / (norm(a) * norm(b))
    model = AutoModel.from_pretrained(
        "jinaai/jina-embeddings-v2-base-code", trust_remote_code=True
    )

    with open("137.cpp", "r") as f:
        incorrect = f.readlines()
    with open("144.cpp", "r") as f:
        correct = f.readlines()
    incorrect = [x.strip() for x in incorrect if x.strip()]
    correct = [x.strip() for x in correct if x.strip()]
    code = correct + incorrect
    embeddings = model.encode(code)

    for i in range(len(correct)):
        print(cos_sim(embeddings[i], embeddings[len(correct) :]))
    return embeddings
