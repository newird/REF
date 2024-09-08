#include<iostream>
using namespace std;
#define max(a,b) a>b?a:b
template<class T>
class Heap {
public:
	int maxSize;
	int curSize;
	T* heap;
	Heap(int size = 0) :maxSize(size), curSize(0), heap(new T[size]) {}
	~Heap() {
		delete[]heap;
	}
	bool insert(const T& item) {
		if (full())
			return false;
		heap[curSize] = item;
		siftUp(curSize++);
		return true;
	}
	bool removeM(T& item) {
		if (empty)
			return false;
		item = heap[0];
		heap[0] = heap[curSize - 1];
		curSize--;
		siftDown(0, curSize - 1);
		return true;
	}
	T& M() { return heap[0]; }
	bool empty() { return curSize == 0; }
	bool full() { return curSize == maxSize; }
	virtual bool heapComp(T& a, T& b)=0;
	void siftDown(int start, int end) {
		int i = start, j = 2 * i + 1;
		T temp = heap[i];
		while (j <= end) {
			if (j < end && this->heapComp(heap[j + 1], heap[j]))
				j++;
			if (this->heapComp(temp, heap[j]) || temp == heap[j])
				break;
			else {
				heap[i] = heap[j];
				i = j;
				j = i * 2 + 1;
			}
		}
		heap[i] = temp;
	}
	void siftUp(int start) {
		int j = start, i = (j - 1) / 2;
		T temp = heap[j];
		while (j > 0) {
			if (this->heapComp(heap[i], temp) || heap[i] == temp)
				break;
			else {
				heap[j] = heap[i];
				j = i;
				i = (j - 1) / 2;
			}
		}
		heap[j] = temp;
	}
	void swap(int u, int v) {
		T temp = heap[u];
		heap[u] = heap[v];
		heap[v] = temp;
	}
};
template<class T>
class MaxHeap :public Heap<T> {
public:
	MaxHeap(int sz = 0):Heap<T>(sz){}
	bool heapComp(T& a, T& b) { return a > b; }
};
template<class T>
class MinHeap :public Heap<T> {
public:
	MinHeap(int sz = 0):Heap<T>(sz){}
	bool heapComp(T& a, T& b) { return a < b; }
};
class happyMovie {
public:
	long long maxHappy;
	long long sum;
	MinHeap<long long> *mh;
	int movieNum;
	int maxMovie;
	int decay;
	happyMovie() {
		cin >> movieNum >> maxMovie >> decay;
		maxHappy = 0;
		mh = new MinHeap<long long>(maxMovie);
		sum = 0;
	}
	void letsDoThis() {
		long long input;
		for (long long i = 1; i <= movieNum; i++) {
			cin >> input;
			if (input <= 0)
				continue;
			if (!mh->full()) {
				mh->insert(input);
				sum += input;
				maxHappy = max(sum-i*decay, maxHappy);
			}
			else {
				if (input > mh->M()) {
					sum += input - mh->M();
					maxHappy = max(sum - i * decay, maxHappy);
					mh->M() = input;
					mh->siftDown(0, maxMovie - 1);
				}
			}
		}
		cout << maxHappy << endl;
	}
};
int main() {
	happyMovie hm;
	hm.letsDoThis();
}