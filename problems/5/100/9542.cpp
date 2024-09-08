#include <iostream>
using namespace std;

const int DefaultSize = 10;

template<class T, class E>
class MinHeap {
public:
	MinHeap(int sz = DefaultSize);
	MinHeap(E arr[], int n);
	~MinHeap() {
		delete[]heap;
	}
	bool Insert(const E& x);
	bool RemoveMin(E& x);
	bool IsEmpty()const {
		return (curSize == 0);
	}
	bool IsFull() const {
		return curSize == maxSize;
	}
	void MakeEmpty() {
		curSize = 0;
	}

	E* heap;//存放最小堆中元素的数组
	int curSize;
	int maxSize;
	void siftDown(int start, int n);//从start到n下滑调整成最小堆
	void siftUp(int start);//从start到0上滑调整成最小堆
};

template<class T, class E>
MinHeap<T, E>::MinHeap(int maxsz) {
	if (maxsz > DefaultSize)
		maxSize = maxsz;
	else
		maxSize = DefaultSize;
	heap = new E[maxSize];
	curSize = 0;
}

template<class T, class E>
MinHeap<T, E>::MinHeap(E array[], int n) {
	if (n > DefaultSize)
		maxSize = n;
	else
		maxSize = DefaultSize;
	heap = new E[maxSize];
	for (int i = 0; i < n; ++i) {
		heap[i] = i;
	}
	curSize = n;
	int start = (curSize - 2) / 2;//找到开始调整位置：最后的分支节点
	while (start >= 0) {//从下往上逐步调整
		siftDown(start, curSize - 1);//每次调整为下滑调整
		--start;
	}
}

template <class T, class E>
void MinHeap<T, E>::siftDown(int start, int n) {//从start开始比较到n，从上往下比较，若子女的关键码比当前节点小，则下滑，直到适当位置（在左右子女已为最小堆的情况下）
	int cur = start, b = 2 * cur + 1;
	E temp = heap[cur];
	while (b <= n) {
		if (b < n && heap[b] > heap[b + 1])//使b成为关键码较小的子女
			++b;
		if (temp <= heap[b])//已经找到合适位置
			break;
		else {
			heap[cur] = heap[b];//将关键码小的子女上浮，
			cur = b;
			b = 2 * cur + 1;//继续往下层比较
		}
	}
	heap[cur] = temp;
}

template <class T, class E>
void MinHeap<T, E>::siftUp(int start) {//从start到0，从下往上比较，若子女的值小于父节点的值，则交换（除了当前节点外，其余节点已经构成最小堆的前提下）
	int cur = start, a = (cur - 1) / 2;
	E temp = heap[cur];
	while (cur > 0) {
		if (heap[a] <= temp)//已经找到合适位置
			break;
		else {//交换
			heap[cur] = heap[a];
			cur = a;
			a = (cur - 1) / 2;//往上一层继续比较
		}
	}
	heap[cur] = temp;
}

template <class T, class E>
bool MinHeap<T, E>::RemoveMin(E& x) {
	if (curSize == 0) {
		cout << "Heap empty" << endl;
		return false;
	}
	x = heap[0];
	heap[0] = heap[curSize - 1];//把最后一个结点挪到根的位置
	--curSize;
	siftDown(0, curSize - 1);//向下调整
	return true;
}

template <class T, class E>
bool MinHeap<T, E>::Insert(const E& x) {
	if (curSize == maxSize) {
		cout << "Heap Full" << endl;
		return false;
	}
	heap[curSize] = x;//插到最后面
	siftUp(curSize);//向上调整
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
	MinHeap<long long, long long> hp(n);//堆中存放下标
	long long res = 0, total = 0, temp = 0;
	long long x;
	for (int i = 0; i < n; ++i) {
		if (hp.curSize < m && a[i] > 0) {
			hp.Insert(a[i]);
			total += a[i];
			temp = total - d * (i + 1);
			if (temp > res) {
				res = temp;//更新结果
			}
		}
		else if (hp.curSize >= m && a[i] > hp.heap[0]) {
			hp.RemoveMin(x);
			hp.Insert(a[i]);
			total = total - x + a[i];
			temp = total - d * (i + 1);
			if (temp > res) {
				res = temp;//更新结果
			}
		}
	}
	
	cout << res;
	return 0;
}