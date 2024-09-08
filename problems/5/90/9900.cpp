#include<iostream>
using namespace std;
void siftDown(long long start, long long  m, long long* heap)
{
	long long i = start, j = 2 * i + 1;
	long long temp = heap[i];
	while (j <= m)
	{
		if (j<m && heap[j]>heap[j + 1])
			j++;
		if (temp <= heap[j])
			break;
		else
		{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;
}
int main()
{
	long long   n, m, d;
	cin >> n >> m >> d;
	long long * a=new long long[n];
	for (long long i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	long long* heap = new long long[m];
	long long size = 0;
	long long result = 0;
	long long  maxsum = 0;
	for (long long i = 1; i <= n; i++)
	{
		if (a[i - 1] < 0)
			continue;
		else
		{
			if (a[i - 1] > 0 && size < m)
			{
				if (result + a[i - 1] - i * d > maxsum)
					maxsum = result + a[i - 1] - i * d;
				result += a[i - 1];
				heap[size] = a[i - 1];
				size++;
				if (size == m)
				{

					int currentSize = m;
					int currentPos = (currentSize - 2) / 2;
					while (currentPos >= 0)
					{
						siftDown(currentPos, currentSize - 1, heap);
						currentPos--;
					}//自下向上调整为最小堆 
				}
			}
			else if (a[i - 1] > 0)
			{

				if (a[i - 1] > heap[0])
				{
					if (maxsum < result - heap[0] + a[i - 1] - i * d)
						maxsum = result - heap[0] + a[i - 1] - i * d;
					heap[0] = a[i - 1];
					siftDown(0, size - 1, heap);
				}
				else
					continue;
			}
			else
			{
				continue;
			}
		}
	}

	cout << maxsum;



}
