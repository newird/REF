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
	int a[100000];
	int b[100000];
	int big = n;
	int jumlah = 0;

	for (int i = 0;i < 100000; i = i + 1)
	{
		a[i] = 0;
		b[i] = 0;
	}

	if (m > n)
	{
		big = m;
	}
	
	for (int i = big-1; i >= big - n ; i = i - 1) 
	{
		cin >> a[i];
	}

	for (int i = big-1; i >= big - m ; i = i - 1) 
	{
		cin >> b[i];
	}

	for (int i = 0; i < big;i = i + 1)
	{
		jumlah = a[i] + b[i];
		if (jumlah >= 10)
		{
			cout << jumlah - 10;
			a[i + 1] = a[i + 1] + 1;
		}
		else
		{
			cout << jumlah;
		}
	}

}