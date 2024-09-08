#include<iostream>

using namespace::std;

int main()
{
	int n, m;
	long long d;
	long long pro = 0;
	cin >> n >> m >> d;
	long long sum[2][2000000] = { 0 };
	int a[2000000] = { 0 };
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j >= m - i && j >= 0; j--)
		{
			if (j == m)sum[i%2][j] = -d * i;
			else if (i == 1)sum[i%2][j] = a[1] - d;
			else sum[i%2][j] = max(sum[1-i%2][j] - d, sum[1-i%2][j +1] - d + a[i]);
			if (sum[i%2][j] > pro)pro = sum[i%2][j];
		}

	}

	cout << pro;




	return 0;
}