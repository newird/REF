#include<iostream>

using namespace::std;

int main()
{
	int n, m,d;
	int pro = 0;
	cin >> n >> m >> d;
	long long sum[200000][10] = { 0 };
	long long a[200000] = { 0 };
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j >= m - i&&j>=0; j--)
		{
			if (j == m)sum[i][j] = -d * i;
			else if (i == 1)sum[i][j] = a[1] - d;
			else sum[i][j] = max(sum[i - 1][j] - d, sum[i - 1][j - 1] - d + a[i]);
			if (sum[i][j] > pro)pro = sum[i][j];
		}

	}

	cout << pro;




	return 0;
}