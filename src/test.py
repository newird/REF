import torch
from transformers import BertTokenizer, BertModel
from scipy.spatial.distance import cosine
from load import seq

tokenizer = BertTokenizer.from_pretrained("bert-base-uncased")
model = BertModel.from_pretrained("bert-base-uncased")

a = seq("debug_137.txt")
b = seq("debug_144.txt")


def sentence_to_vec(sentence, tokenizer, model):
    inputs = tokenizer(
        sentence, return_tensors="pt", padding=True, truncation=True, max_length=512
    )
    outputs = model(**inputs)
    return outputs.last_hidden_state.mean(1)


a_vecs = [sentence_to_vec(sentence, tokenizer, model) for sentence in a]
b_vecs = [sentence_to_vec(sentence, tokenizer, model) for sentence in b]

similarity_matrix = torch.zeros((len(a), len(b)))

for i, a_vec in enumerate(a_vecs):
    for j, b_vec in enumerate(b_vecs):
        a_vec_1d = a_vec.detach().numpy().flatten()
        b_vec_1d = b_vec.detach().numpy().flatten()

        similarity = 1 - cosine(a_vec_1d, b_vec_1d)
        similarity_matrix[i][j] = similarity
print(similarity_matrix)
