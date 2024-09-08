#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

void get_min_heap(int A[], int i, int size) {
    int left = 2 * i + 1, right = 2 * i + 2, lowest = i;
    if (left < size && A[left] < A[lowest]) {
        lowest = left;
    }
    if (right < size && A[right] < A[lowest]) {
        lowest = right;
    }
    if (lowest != i) {
        int temp = A[i];
        A[i] = A[lowest];
        A[lowest] = temp;
        get_min_heap(A, lowest, size);
    }
}

int get_max(int n, int m, int d, int A[]) {
    int last = 0, chance = m - 1, temp_max = 0, max_value = 0;
    int* min_heap;
    if (m == 1) {
        min_heap = NULL;
    }
    else {
        min_heap = new int[m - 1]{0};;
    }
    for (last; last < n; last++) {
        if (last > 0) {
            temp_max -= A[last - 1];
        }
        temp_max += A[last] - d;
        if (m > 1) {
            if (last > 0 && chance > 0 && A[last - 1] > 0) {
                temp_max += A[last - 1];
                min_heap[0] = A[last - 1];
                get_min_heap(min_heap, 0, m - 1);
                chance--;
            }
            else if (last > 0 && chance == 0 && A[last - 1] > min_heap[0]) {
                temp_max += A[last - 1] - min_heap[0];
                min_heap[0] = A[last - 1];
                get_min_heap(min_heap, 0, m - 1);
            }
        }
        max_value = max(temp_max, max_value);
    }
    delete[] min_heap;
    return max_value;
}

int main() {
	int n, m, d, max;
	cin >> n >> m >> d;
	int* A = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
    max = get_max(n, m, d, A);
    cout << max;
    delete[] A;
    return 0;
}
