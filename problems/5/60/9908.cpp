#include <iostream>
#include <cmath>
#define DefaultSize 10;
using namespace std;
template <class E>
class MinHeap {
public:
	MinHeap(int sz);
	~MinHeap() { delete[]heap; }
	bool Insert(const E& x);
	bool RemoveMin();
	bool IsEmpty();

	E* heap;
	int currentSize;
	int maxSize;
	void siftDown(int start, int m);
	void siftUp(int start);
	long int sum();
};
template<class E>
long int MinHeap<E>:: sum()
{
	long int result=0;
	for (int i= 0; i < currentSize; i++)
		result += heap[i];
	return result;
}
template<class E>
MinHeap<E>::MinHeap(int sz)
{
	maxSize = sz;
	heap = new E[maxSize];
	currentSize = 0;
}

template<class E>
void MinHeap<E>::siftDown(int start, int m)
{
	int i = start, j = 2 * i + 1;
	E temp = heap[i];
	while (j <= m)
	{
		if (j < m && heap[i] > heap[j + 1])j++;
		if (temp <= heap[i])break;
		else { heap[i] = heap[j]; i = j; j = 2 * i + 1; }
	}
	heap[i] = temp;
}

template<class E>
void MinHeap<E>::siftUp(int start)
{
	int j = start, i = (j - 1) / 2;
	E temp = heap[j];
	while (j > 0)
	{
		if (heap[i] <= temp)break;
		else { heap[j] = heap[i]; j = i; i = (j - 1) / 2; }
	}
	heap[j] = temp;
}

template <class E>
bool MinHeap<E>::Insert(const E& x)
{
	heap[currentSize] = x;
	siftUp(currentSize);
	currentSize++;
	return true;
}

template <class E>
bool MinHeap<E>::RemoveMin()
{
    heap[0] = heap[currentSize - 1];
	currentSize--;
	siftDown(0, currentSize - 1);
	return true;
}

int main() {
	int n, m, d;

	long result = 0;
	cin >> n >> m >> d;
	long input;
	MinHeap<int> heap(n);
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input > 0) {
			result = max(result,
				input - d * (i + 1) + heap.sum()
			);
			heap.Insert(input);
			if (heap.currentSize >= m)
				heap.RemoveMin();
		}
	}
	cout << result << endl;
	return 0;
}