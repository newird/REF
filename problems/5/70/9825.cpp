#include <iostream>
using namespace std;
#include <stdio.h>

//本题和上次的求第k大数相似
//要求最大幸福度，可以求MAX(A1，A2，A3...)
//其中Ai是指，最后一次看电影为第i次，再在前i-1次中找出最大的x <= m-1个数字,这些数字的和还要减去d*i
// 为了遍历一次就求出MAX(A1，A2，A3...)，要维护一个有求和方法的堆（在堆中增加一个sum成员），再用m-1大小的数组存储大小不一的堆
// 这些堆用于计算不同的x情况下的最大值

//最初的解决方法，会突破内存上限
// 优化方法：只保留一个堆，用m-1的最小堆如何求出前k大数之和？
//排除根节点后，还剩m-2大数，此时可以考虑继续排除左右根
//排除直到剩余k大数为止，此时通过sum减出新的sum，一路上可以迭代出所有需要的sum
//为了满足迭代操作，使用优先级队列存储排除根节点后产生的平行/无父子关系根节点，每次排除最小的根节点，将新产生的根节点计入优先级队列


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

	class myQ {
		struct QNode {
			size_t index;
			QNode* next;
		};
		QNode* dummy;

	public:
		E* heap;
		myQ() {
			dummy = new QNode{ 0, nullptr };
		}
		~myQ() {
			while (dummy != nullptr) {
				QNode* td = dummy;
				dummy = dummy->next;
				delete td;
			}
		}
		void insert(size_t add) {	//传入的是heap地址index
			QNode* cur = dummy;
			while (cur->next != nullptr) {
				if (heap[cur->next->index] >= heap[add]) {
					break;
				}
				cur = cur->next;
			}

			QNode* adder = new QNode{ add, cur->next };
			cur->next = adder;
		}
		int top() { return dummy->next->index; }	
		void pop() {
			QNode* td = dummy->next;
			dummy->next = td->next;
			delete td;
		}
		bool empty() { return dummy->next == nullptr; }
	}q;

public:
	MinHeap(int capacity_) {
		capacity = capacity_;
		heap = new E[capacity_];
		size = 0;
		sum = 0;
		q.heap = heap;
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

	void TODO(int n, int d) {
		//随着遍历向最小堆中添加元素
		//每次添加之前，考虑每个sum + input - d * i是否是max

		int input;
		int max = 0;	//不看的最大值

		//第一次输入特殊处理
		readint(input);
		max = max > (input - d * 1) ? max : (input - d * 1);	//看1次，且最后一次看为第1次 的最大值
		insert(input);

		for (int i = 2; i <= n; i++) {
			readint(input);
			max = max > (input - d * i) ? max : (input - d * i);	//看1次，且最后一次看为第i次 的最大值
			//开始处理看多次最大值
			int tempSum = sum;
			max = max > (tempSum + input - d * i) ? max : (tempSum + input - d * i);	//看min(i, m - 1)次，且最后一次看为第i次 的最大值
			q.insert(0);	
			while (!q.empty()) {
				tempSum -= heap[q.top()];
				int add1 = 2 * q.top() + 1;
				q.pop();
				if (add1 < size)
					q.insert(add1);
				if (add1 + 1 < size)
					q.insert(add1 + 1);
				
				max = max > (tempSum + input - d * i) ? max : (tempSum + input - d * i);	//看min(i, m - 1) - time次，且最后一次看为第i次 的最大值
			}
			if (i < capacity + 1) {
				insert(input);
			}
			else {
				if (input > heap[0]) {
					insert(input);
				}
			}
		}

		cout << max;
	}

};

int main() {
	int n, m, d;
	readint(n);
	readint(m);
	readint(d);
	MinHeap<int> l(m - 1);
	l.TODO(n, d);
	
	return 0;
}