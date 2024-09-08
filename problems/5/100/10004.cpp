#include <iostream>
using namespace std;

//这个问题可以拆解为
//以第i次电影为结尾，求出1...i-1次电影的幸福度总和（最多m-1次），再加上第i次幸福度，再减去d*i
//可以维护一个大小为m-1的最小堆，其中储存了最大的m-1个正数（只需要记录正数，因为前i-1个的计算是贪心的）

#define max(a, b) ((a) > (b) ? (a) : (b))

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
	long long sum;
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
			sum += (long long)data;
		}
		else if (data > heap[0]) {
			sum += (long long)data;
			sum -= (long long)heap[0];
			heap[0] = data;
			siftDown();
		}
	}

	long long getSum() { return sum; }
};

int main() {
	int n, m, d;
	readint(n);
	readint(m);
	readint(d);

	MinHeap<int> h(m - 1);
	long long res = 0;	//最小为不看电影
	int input;
	for (int i = 1; i <= n; i++) {	//第i次输入
		readint(input);
		if (input > 0) {	//只有大于0的幸福度才可能被看，否则既不作为最后一次电影，也不可能录入堆
			//先不更新堆，考虑旧堆最大值和新电影组成的新幸福度
			res = max(res, (h.getSum() + (long long)input - (long long)d * (long long)i));
			//然后更新堆,堆满了的话要比较，否则直接加,这些判断含在inset函数中
			h.insert(input);
		}
	}
	cout << res;
	return 0;
}