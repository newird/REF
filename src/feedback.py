import numpy as np
from align import align

# Define the similarity matrix

similarity_matrix = align()

from scipy.optimize import linear_sum_assignment

cost_matrix = similarity_matrix.max() - similarity_matrix

row_ind, col_ind = linear_sum_assignment(cost_matrix)

matches = list(zip(row_ind, col_ind))

import numpy as np

matrix = align()

max_indices = np.argmax(matrix, axis=1)

for row_index, col_index in enumerate(max_indices):
    print(
        f"Row {row_index} best matches with Column {col_index % 19} with a score of {matrix[row_index, col_index]}"
    )
# print(matches, similarity_matrix[row_ind, col_ind].tolist())
#
# cost_matrix = -similarity_matrix
#
# # Apply the Hungarian algorithm to find the optimal assignment
# row_indices, col_indices = linear_sum_assignment(cost_matrix)
#
# # For each row, find its best matching column
# for row, col in zip(row_indices, col_indices):
#     print(
#         f"Row {row} best matches with Column {col} with a score of {similarity_matrix[row, col]}"
#     )
