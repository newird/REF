#include<iostream>

using namespace std;

long long maxsum = 0;
long long res = 0;

class MinHeap {                   //最小堆
public:
	MinHeap(long long arr[], long long n, long long d);
	long long* heap;
	int currentSize;
	void siftDown(int start, int m);
};

MinHeap::MinHeap(long long arr[], long long n, long long d) {
    currentSize = n;
	heap = new long long[currentSize];
	for (int i = 0; i < n; i++) {
		heap[i] = 0;
	}
	long long cnt = 0, i = 0;
	while (cnt < n && i < n) {
		if (arr[i] > 0) {
			heap[cnt] = arr[i];
			maxsum = maxsum + arr[i];
			if (maxsum - (i + 1) * d > res)
				res = maxsum - (i + 1) * d;
			cnt++;
		}
		i++;
	}

	int currentPos = (currentSize - 2) / 2;
	while (currentPos >= 0) {
		siftDown(currentPos, currentSize - 1);
		currentPos--;
	}
};
void MinHeap::siftDown(int start, int m) {
	int i = start, j = 2 * i + 1;
	int tmp = heap[i];
	while (j <= m) {
		if (j < m && heap[j] > heap[j + 1]) j++;
		if (tmp <= heap[j]) break;
		else{ 
            heap[i] = heap[j]; 
            i = j; 
            j = 2 * j + 1; 
        }
	}
	heap[i] = tmp;
};

int main() {
	long long n, m, d;
	cin>>n>>m>>d;
	long long a[200000];
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	MinHeap heapchanging(a, m, d);      //直接把前m个置堆，再从m+1往后维护堆并尝试替换
	for (int j = m; j < n; j++) {
		if (a[j] > heapchanging.heap[0]) {
			maxsum = maxsum + a[j] - heapchanging.heap[0];
			heapchanging.heap[0] = a[j];
			heapchanging.siftDown(0, m - 1);
			if (maxsum - (j + 1) * d > res)
				res = maxsum - (j + 1) * d;
		}
	}
	cout<<res;
	return 0;
}