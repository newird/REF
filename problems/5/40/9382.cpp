#include<iostream>
#include<string.h>
using namespace std;
int DefaultSize=200000;
long long maxsum = 0;
long long flag;
class MinHeap {
public:
	MinHeap(int sz = DefaultSize);
	MinHeap(long long arr[], long long n, long long d);
	bool IsEmpty() const{
		return currentSize == 0;
	}
	void MakeEmpty() { currentSize = 0; }
	long long* heap;
	int currentSize;
	int maxHeapSize;
	void siftDown(int start, int m);
	long long getSum(long long n,long long d) {
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
			flag = i;
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
	cin >> n >> m >> d;
	long long a[200000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long sum;
	MinHeap heap(a, m, d);
	sum = heap.getSum(m - 1, d);
	for (int j = m; j < n; j++) {
		if (a[j] > heap.heap[0]) {
			sum = sum + a[j] - heap.heap[0] - d * (j - flag);
			flag = j;
			heap.heap[0] = a[j];
			heap.siftDown(0, m - 1);
			if (sum > maxsum)
				maxsum = sum;
		}
	}
	cout << maxsum;
	return 0;
}