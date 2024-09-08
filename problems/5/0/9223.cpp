#include<iostream>
using namespace std;
class minHeap
{
public:
	long maxSize = 0, * heap, size = 0;
	minHeap(long sz) :maxSize(sz + 1) { heap = new long[maxSize]; }
	long sum = 0;
	void push(long val)
	{
		heap[size] = val;
		long j = size, i = (j - 1) / 2;
		long temp = heap[j];
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
		long i = 0, j = 2 * i + 1;
		long temp = heap[i];
		while (j <= size)
		{
			if (j<size && heap[j]>heap[j + 1])j++;
			if (temp <= heap[j])break;
			else { heap[i] = heap[j], i = j, j = 2 * i + 1; }
		}
		heap[i] = temp;
	}
	long get() { return heap[0]; }
};

long* a;

long main() {
	long n, m, d;
	cin >> n >> m >> d;;
	a = new long[n + 1];//第i部电影幸福值
	a[0] = 0;
	minHeap heap(m-1);
	long max_a = 0;
	for (long i = 1; i <= n; i++)
	{
		cin >> a[i];
		max_a = max(heap.sum - d * i + a[i], max_a);
		if (heap.size < m-1)
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
	cout << max_a;
}
