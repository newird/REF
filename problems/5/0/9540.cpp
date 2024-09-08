#include <iostream>
using namespace std;

const int DefaultSize = 10;

//最大堆
template<class T, class E>
class MaxHeap {
public:
	MaxHeap(int sz = DefaultSize);
	MaxHeap(E arr[], int n);
	bool RemoveMax(E& x, E arr[]);
	bool Insert(const E& x, E arr[]);
	bool IsEmpty()const {
		return (curSize == 0);
	}
	bool IsFull() const {
		return curSize == maxSize;
	}
	void MakeEmpty() {
		curSize = 0;
	}
	E getMax() {
		return heap[0];
	}
	int Size() {
		return curSize;
	}
private:
	E* heap;//存放最大堆中元素的数组
	int curSize;
	int maxSize;
	void siftDown(int start, int n, E arr[]);//从start到n下滑调整成最大堆
	void siftUp(int start, E arr[]);//从start到0上滑调整成最大堆
};

template<class T, class E>
MaxHeap<T, E>::MaxHeap(int maxsz) {
	if (maxsz > DefaultSize)
		maxSize = maxsz;
	else
		maxSize = DefaultSize;
	heap = new E[maxSize];
	curSize = 0;
}

template<class T, class E>
MaxHeap<T, E>::MaxHeap(E array[], int n) {
	if (n > DefaultSize)
		maxSize = n;
	else
		maxSize = DefaultSize;
	heap = new E[maxSize];
	for (int i = 0; i < n; ++i) {
		heap[i] = i;
	}
	curSize = n;
	int start = (curSize - 2) / 2;
	while (start >= 0) {
		siftDown(start, curSize - 1, array);
		--start;
	}
}

template <class T, class E>
void MaxHeap<T, E>::siftDown(int start, int n, E arr[]) {
	int cur = start, b = 2 * cur + 1;
	E temp = heap[cur];
	while (b <= n) {
		if (b < n && arr[heap[b]] < arr[heap[b + 1]])
			++b;
		if (arr[temp] >= arr[heap[b]])
			break;
		else {
			heap[cur] = heap[b];
			cur = b;
			b = 2 * cur + 1;
		}
	}
	heap[cur] = temp;
}

template <class T, class E>
void MaxHeap<T, E>::siftUp(int start, E arr[]) {
	int cur = start, a = (cur - 1) / 2;
	E temp = heap[cur];
	while (cur > 0) {
		if (arr[heap[a]] >= arr[temp])
			break;
		else {
			heap[cur] = heap[a];
			cur = a;
			a = (cur - 1) / 2;
		}
	}
	heap[cur] = temp;
}

template <class T, class E>
bool MaxHeap<T, E>::RemoveMax(E& x, E arr[]) {
	if (curSize == 0) {
		cout << "Heap empty" << endl;
		return false;
	}
	x = heap[0];
	heap[0] = heap[curSize - 1];
	--curSize;
	siftDown(0, curSize - 1, arr);
	return true;
}

template <class T, class E>
bool MaxHeap<T, E>::Insert(const E& x, E arr[]) {
	if (curSize == maxSize) {
		cout << "Heap Full" << endl;
		return false;
	}
	heap[curSize] = x;
	siftUp(curSize, arr);
	++curSize;
	return true;
}


int main() {
	int n, m;
	long long d;
	cin >> n >> m >> d;
	long long* a = new long long[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	//for (int i = 0; i < n; ++i) {
	//	a[i] = a[i] - (d * (i + 1));//先将每天都当成是最后一天
	//}
	MaxHeap<long long, long long> hp(a, n);//堆中存放下标
	long long res = 0;
	long long index, cur = -1;//cur为当前最后一天的下标
	while (m > 0 && !hp.IsEmpty()) {
		hp.RemoveMax(index, a);
		long long temp;
		if (index > cur) {//最后一天下标增大
			temp = res + a[index] + d * (cur + 1) - d * (index + 1);
			if (temp > res) {
				res = temp;//更新结果
				cur = index;//更新最后一天的下标
				--m;
			}
			else {
				hp.Insert(index, a);
			}
		}
		else {//最后一天下标不变
			temp = res + a[index];
			if (temp > res) {
				res = temp;//更新结果
				--m;
			}
			else {
				hp.Insert(index, a);
			}
		}
	}
	
	cout << res;
	return 0;
}