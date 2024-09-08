#include<iostream>
#include <stdio.h>

inline void readlong(long long& a) {
	a = 0; char c; long long sgn = 1;
	while ((c = getchar()) < 48) if (c == '-') sgn = -1;
	do a = a * 10 + (c ^ 48);
	while ((c = getchar()) > 47);
	a *= sgn;
}
using namespace std;
int DefaultSize = 2000;
long long maxsum = 0;
class MinHeap {
public:
	MinHeap(int sz = DefaultSize);
	MinHeap(long long arr[], long long n, long long d);
	bool IsEmpty() const {
		return currentSize == 0;
	}
	void MakeEmpty() { currentSize = 0; }
	long long* heap;
	int currentSize;
	int maxHeapSize;
	void siftDown(int start, int m);
	long long getSum(long long n, long long d) {
		long long res = 0;
		for (int i = 0; i < currentSize; i++) {
			res = res + heap[i];
		}
		return res - (n + 1) * d;
	}
};
MinHeap::MinHeap(int sz) {
	maxHeapSize = (DefaultSize < sz) ?
		sz : DefaultSize;
	heap = new long long[maxHeapSize];
	currentSize = 0;
};
MinHeap::MinHeap(long long arr[], long long n, long long d) {
	maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
	heap = new long long[maxHeapSize];
	for (int i = 0; i < n; i++) {
		heap[i] = 0;
	}
	currentSize = n;
	long long cnt = 0, i = 0;
	while (cnt < n && i < n) {
		if (arr[i] > 0) {
			heap[cnt] = arr[i];
			long long x = getSum(i, d);
			if (x > maxsum)
				maxsum = x;
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
	int temp = heap[i];
	while (j <= m) {
		if (j < m && heap[j] > heap[j + 1]) j++;
		if (temp <= heap[j]) break;
		else { heap[i] = heap[j]; i = j; j = 2 * j + 1; }
	}
	heap[i] = temp;
};
int main() {
	long long n, m, d;
	readlong(n);
	readlong(m);
	readlong(d);
	long long a[2000];
	for (int i = 0; i < n; i++) {
		readlong(a[i]);
	}
	MinHeap heap(a, m, d);
	for (int j = m; j < n; j++) {
		if (a[j] > heap.heap[0]) {
			heap.heap[0] = a[j];
			heap.siftDown(0, m - 1);
			long long x = heap.getSum(j, d);
			if (x > maxsum)
				maxsum = x;
		}
	}
	printf("%lld", maxsum);
	return 0;
}