
#include <vector>
#include <iostream>
#include<math.h>
using namespace std;
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int main()
{
	int n, m;
	cin >> n >> m;
	int cf = 0;
	int* s0 = new int[n];
	int* s1 = new int[m];
	int* sum = new int[max(m, n) + 1];
	for (int i = 0; i < n; ++i)
	{
		
		cin >> s0[i];
		
	}
	for (int i = 0; i < m; ++i)
	{

		cin >> s1[i];

	}
	int i = 0;
	for (; i < max(m, n) + 1; ++i)
	{
		if(i<n&&i<m)
		{
			sum[i] = s1[i] + cf + s0[i];
			if (sum[i] >= 10)
			{
				sum[i] = sum[i] - 10;
				cf = 1;
			}
			else
				cf = 0;
		}
		if (i >= n && i < m)
		{
			sum[i] = s1[i] + cf;
			if (sum[i] >= 10)
			{
				sum[i] = sum[i] - 10;
				cf = 1;
			}
			else
				cf = 0;
		}
		if (i >= m && i <n)
		{
			sum[i] = s0[i] + cf;
			if (sum[i] >= 10)
			{
				sum[i] = sum[i] - 10;
				cf = 1;
			}
			else
				cf = 0;
		}
		

	}
	sum[i] = cf; 
	int j;
	if (sum[i] == 0)
		j = max(m, n) - 1;
	else
		j = max(m, n);
	for (; j >= 0; --j)
	{
		cout << sum[j];
	}
	
	return 0;
}