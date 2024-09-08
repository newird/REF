#include <iostream>
#include <string.h>
using namespace std;
void HeapAdjust(int* data, int root, int n) {
	int temp = data[root];
	
	for (int i = 2 * root + 1; i <= n; i = 2 * i + 1) 
	{
		if (i < n && data[i] > data[i + 1])
			i++;

		if (temp <= data[i])
			break;
		data[root] = data[i];
		root = i;
	}
	data[root] = temp;
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
			HeapAdjust(max_num,0,m);
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