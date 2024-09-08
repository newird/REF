#include <iostream>
using namespace std;

const int MAX_SIZE = 200000;

int heap[MAX_SIZE];
int heapSize = 0;

void push(int value) {
    heap[heapSize] = value;
    int index = heapSize;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
    heapSize++;
}

void pop() {
    if (heapSize == 0) {
        return;
    }
    heap[0] = heap[--heapSize];
    int index = 0;
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        if (left < heapSize && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heapSize && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

int top() {
    if (heapSize > 0) {
        return heap[0];
    } else {
        return 0;
    }
}

int main() {
    int n, m, d;
    int result = 0;
    int sum = 0;

    cin >> n >> m >> d;
    int arr[MAX_SIZE];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            if (heapSize < m) { 
                push(arr[i]);
                sum += arr[i];
            } else if (arr[i] > top()) { 
                sum -= top(); 
                pop();
                push(arr[i]);
                sum += arr[i];
            }
            result = max(result, sum - d * (i + 1)); 
        }
    }
    cout << result << endl;

    return 0;
}
