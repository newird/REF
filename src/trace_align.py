from load import seq
from transformers import AutoTokenizer, AutoModel
import torch

# Assuming you've implemented seq function to load the sequences correctly
tokenizer = AutoTokenizer.from_pretrained("microsoft/codebert-base")
model = AutoModel.from_pretrained("microsoft/codebert-base")

filea = input()
fileb = input()

# Load your sequences
seqa = seq(filea)  # This should be a list of strings
seqb = seq(fileb)  # This should be a list of strings


# Tokenize and encode sequences
inputs_a = tokenizer(seqa, padding=True, truncation=True, return_tensors="pt")
inputs_b = tokenizer(seqb, padding=True, truncation=True, return_tensors="pt")

# Generate embeddings
outputs_a = model(**inputs_a)
outputs_b = model(**inputs_b)

embedding_a = outputs_a.last_hidden_state.mean(dim=1)  # Taking the mean across tokens
embedding_b = outputs_b.last_hidden_state.mean(dim=1)  # Taking the mean across tokens

# Compute cosine similarity
from torch.nn.functional import cosine_similarity

similarity = cosine_similarity(embedding_a, embedding_b)
print(similarity)
