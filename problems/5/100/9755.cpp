#include <iostream>
using namespace std;

#define N 200000

long long int sum;
long long int y = 0;
long long int heap[N];
long long int heapSize = 0;

void push(long long int value) {
    heap[heapSize] = value;
    int current = heapSize;
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap[current] < heap[parent]) {
         
            long long int temp = heap[current];
            heap[current] = heap[parent];
            heap[parent] = temp;
            current = parent;
        } else {
            break;
        }
    }
    heapSize++;
}

void pop() {
    if (heapSize == 0) return;
    heapSize--;
    heap[0] = heap[heapSize];
    int current = 0;
    while (current * 2 + 1 < heapSize) {
        int child = current * 2 + 1;
        if (child + 1 < heapSize && heap[child] > heap[child + 1]) {
            child++;
        }
        if (heap[current] > heap[child]) {
            
            long long int temp = heap[current];
            heap[current] = heap[child];
            heap[child] = temp;
            current = child;
        } else {
            break;
        }
    }
}

int main() {
    long long int n, m, d, arr[N];
    cin >> n >> m >> d;
    for (long long int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (long long int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            if (heapSize < m) {
                push(arr[i]);
                sum += arr[i];
            }
            else if (arr[i] > heap[0]) {
                sum -= heap[0];
                pop();
                push(arr[i]);
                sum += arr[i];
            }
            y = max(y, sum - d * (i + 1));
        }
    }
    cout << y << endl;

    return 0;
}
