#include <iostream>
#include <string.h>
using namespace std;
void AdjustDown(int* data, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{

		if (data[child + 1] > data[child] && child + 1 < n)
		{
			++child;
		}

		if (data[child] > data[parent])
		{
			int tem = data[parent];
			data[parent] = data[child];
			data[child] = tem;
			parent = child;
			child = parent * 2 + 1;
		}

		else
		{
			break;
		}
	}
}
void HeapSort(int* data, int n)
{

	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(data, n, i);
	}
	int end = n - 1;

	while (end > 0)
	{
		int tem = data[end];
		data[end] = data[0];
		data[0] = tem;
		AdjustDown(data, end, 0);
		--end;
	}
}
int main()
{
	int n,m,d;
	cin >> n >> m >> d;
	int num[n]{};
	for(int i = 1;i <= n;i++)
	{
		cin >> num[i];
	}

	int max_num[m]{};
	long long int max = 0;
	int sum = 0; 
	for(int i = 1;i <= n;i++)
	{
		if(max_num[0] < num[i])
		{
			sum += num[i] - max_num[0];
			max_num[0] = num[i];
			HeapSort(max_num,m);
		}
		if(sum - i * d > max)
		{
			max = sum - i * d;
		}
	}
	
	if(max < 0)
	{
		max = 0;
	}
	cout << max;
	return 0;
}