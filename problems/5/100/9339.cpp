#include <iostream>
using namespace std;
void HeapAdjust(long long int* data, int root, int n) {
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
	long long n,m,d;
	cin >> n >> m >> d;
	long long num[n]{};
	for(int i = 1;i <= n;i++)
	{
		cin >> num[i];
	}

	long long int max_num[m]{};
	long long int max = 0;
	long long int sum = 0; 
	for(int i = 1;i <= n;i++)
	{
		if(max_num[0] < num[i])
		{
			sum += num[i] - max_num[0];
			max_num[0] = num[i];
			HeapAdjust(max_num,0,m-1);
		}
		if(sum - i * d > max)
		{
			max = sum - i * d;
		}
	}
	
	cout << max;
	return 0;
}