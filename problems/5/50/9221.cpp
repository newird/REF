#include<iostream>
using namespace std;
inline void readint(int& a) {
	a = 0; char c; int sgn = 1;
	while ((c = getchar()) < 48) if (c == '-') sgn = -1;
	do a = a * 10 + (c ^ 48);
	while ((c = getchar()) > 47);
	a *= sgn;
}
class minHeap
{
public:
	int maxSize = 0, * heap, size = 0;
	minHeap(int sz) :maxSize(sz + 1) { heap = new int[maxSize]; }
	long sum = 0;
	void push(int val)
	{
		heap[size] = val;
		int j = size, i = (j - 1) / 2;
		int temp = heap[j];
		while (j > 0)
		{
			if (heap[i] <= temp)
				break;
			else
			{
				heap[j] = heap[i];
				j = i;
				i = (j - 1) / 2;
			}
		}
		heap[j] = temp;
		size++;
		sum += val;
	}
	void pop()
	{
		sum -= heap[0];
		heap[0] = heap[size - 1];
		size--;
		int i = 0, j = 2 * i + 1;
		int temp = heap[i];
		while (j <= size)
		{
			if (j<size && heap[j]>heap[j + 1])j++;
			if (temp <= heap[j])break;
			else { heap[i] = heap[j], i = j, j = 2 * i + 1; }
		}
		heap[i] = temp;
	}
	int get() { return heap[0]; }
};

int* a;

int main() {
	int n, m, d;
	readint(n), readint(m), readint(d);
	a = new int[n + 1];//第i部电影幸福值
	a[0] = 0;
	minHeap heap(m-1);
	long max_a = 0;
	for (int i = 1; i <= n; i++)
	{
		readint(a[i]);
		max_a = max(heap.sum - d * i + a[i], max_a);
		if (heap.size < m)
		{
			if (a[i] > 0)
				heap.push(a[i]);
		}
		else
		{
			if (a[i] > heap.get())
			{
				heap.push(a[i]);
				heap.pop();
			}
		}
	}
	printf("%d",max_a);
}