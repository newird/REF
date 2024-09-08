#include <iostream>
using namespace std;
#include <stdio.h>

//本题和上次的求第k大数相似
//要求最大幸福度，可以求MAX(A1，A2，A3...)
//其中Ai是指，最后一次看电影为第i次，再在前i-1次中找出最大的x <= m-1个数字,这些数字的和还要减去d*i
// 为了遍历一次就求出MAX(A1，A2，A3...)，要维护一个有求和方法的堆（在堆中增加一个sum成员），再用m-1大小的数组存储大小不一的堆
// 这些堆用于计算不同的x情况下的最大值


inline void readint(int& a) {
	a = 0; char c; int sgn = 1;
	while ((c = getchar()) < 48) if (c == '-') sgn = -1;
	do a = a * 10 + (c ^ 48);
	while ((c = getchar()) > 47);
	a *= sgn;
}

template <class E>
class MinHeap {
	E* heap;
	int size;
	int capacity;
	int sum;
public:
	MinHeap(int capacity_) {
		capacity = capacity_;
		heap = new E[capacity_];
		size = 0;
		sum = 0;
	}
	E& top() { return heap[0]; }
	void siftDown() {
		int i = 0, j = 2 * i + 1;
		E temp = heap[i];
		while (j < capacity) {
			if (j < capacity - 1 && heap[j] > heap[j + 1]) {
				j++;
			}
			if (temp <= heap[j]) {
				break;
			}
			else {
				heap[i] = heap[j];
				i = j;
				j = 2 * j + 1;
			}
		}
		heap[i] = temp;
	}
	void siftUp(int start) {
		int j = start, i = (j - 1) / 2;
		E temp = heap[j];
		while (j > 0) {
			if (heap[i] <= temp) {
				break;
			}
			else {
				heap[j] = heap[i];
				j = i;
				i = (i - 1) / 2;
			}
		}
		heap[j] = temp;
	}
	void insert(E& data) {
		if (size < capacity) {
			heap[size] = data;
			siftUp(size);
			size++;
			sum += data;
		}
		else {
			sum += data;
			sum -= heap[0];
			heap[0] = data;
			siftDown();
		}
	}

	int getSum() { return sum; }
};

int main() {
	int n, m, d;
	readint(n);
	readint(m);
	readint(d);
	MinHeap<int>** arr = new MinHeap<int>*[m - 1];
	for (int i = 0; i < m - 1; i++) {
		arr[i] = new MinHeap<int>(i + 1);
	}
	
	int max = 0;
	int input;
	for (int i = 1; i <= n; i++) {	//第i次输入，其中size = (j + 1) < i 的最小堆已经满了，可以先求和再考虑更新，否则直接不需考虑地更新
		readint(input);
		int j = 0;
		max = max > (input - d * i) ? max : (input - d * i);
		for (; j + 1 < i && j < m - 1; j++) {
			max = max > (arr[j]->getSum() + input - d * (i)) ? max : (arr[j]->getSum() + input - d * i);
			if (input > arr[j]->top()) {
				arr[j]->insert(input);
			}
		}
		for (; j < m - 1; j++) {
			arr[j]->insert(input);
		}

		
	}
	cout << max;
	return 0;
}