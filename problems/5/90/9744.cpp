#include <iostream>
using namespace std;
#define N 200000
void pushHeap(long long int heap[], int& size, long long int value) {
    heap[size++] = value;
    int idx = size - 1;
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[idx] > heap[parent]) {
            swap(heap[idx], heap[parent]);
            idx = parent;
        }
        else {
            break;
        }
    }
}

void popHeap(long long int heap[], int& size) {
    if (size == 0) return;
    heap[0] = heap[--size];
    int idx = 0;
    while (true) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int largest = idx;
        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != idx) {
            swap(heap[idx], heap[largest]);
            idx = largest;
        }
        else {
            break;
        }
    }
}

int main() {
    long long int n, m, d;
    cin >> n >> m >> d;
    long long int arr[N];

    for (long long int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long int heap[N];
    int size = 0;
    long long int sum = 0;
    long long int y = 0;

    for (long long int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            if (size < m) {
                pushHeap(heap, size, arr[i]);
                sum += arr[i];
            }
            else if (arr[i] > heap[0]) {
                sum -= heap[0];
                popHeap(heap, size);
                pushHeap(heap, size, arr[i]);
                sum += arr[i];
            }
            y = max(y, sum - d * (i + 1));
        }
    }

    cout << y << endl;

    return 0;
}