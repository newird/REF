#include <iostream>
using namespace std;

#define max(a, b) (a > b ? a : b)

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
			if (temp < heap[j]) {
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
			if (heap[i] < temp) {
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
		else if (data > heap[0]){
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
	cin >> n >> m >> d;

	MinHeap<int> h(m - 1);
	int res = 0;	//最小为不看电影
	int input;
	for (int i = 1; i <= n; i++) {	//第i次输入
		cin >> input;
		if (input > 0) {	//只有大于0的幸福度才可能被看，否则既不作为最后一次电影，也不可能录入堆
			//先不更新堆，考虑旧堆最大值和新电影组成的新幸福度
			res = max(res, (h.getSum() + input - d * i));
			//然后更新堆,堆满了的话要比较，否则直接加,这些判断含在inset函数中
			h.insert(input);
		}
	}
	cout << res;
	return 0;
}