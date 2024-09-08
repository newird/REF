#include <iostream>
using namespace std;
#include <stdio.h>

void FUNCT(int n, int m);

int main()
{
	int n, m;
	cin >> n >> m;
	FUNCT(n, m);
	return 0;
}

void FUNCT(int n, int m)
{
	long long a[100000];
	long long b[100000];
	long long c[100000];
	long long jumlah = 0;
	long long big = n;
	long long kali = 0;
	int flag = 1;
	if (m > n)
	{
		big = m;
	}

	for (int i = 0;i < big + 1; i = i + 1)
	{
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}

	for (int i = 0; i < n; i = i + 1)
	{
		cin >> a[i];
	}

	for (int i = 0; i < m; i = i + 1)
	{
		cin >> b[i];
	}

	for (int i = 0; i <= big;i = i + 1)
	{
		int count = 0;
		jumlah = a[i] + b[i];
		while (jumlah >= 10)
		{
			jumlah = jumlah % 10;
			count = count + 1;
		}
		c[i + 1] = c[i + 1] + count;
		c[i] = c[i] + jumlah;
	}

	for (int i = big; i >= 0;i = i - 1)
	{
		cout << c[i];
	}

}