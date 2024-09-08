#include<iostream>
using namespace std;
int main()
{
	int n, m,out=0;
	cin >> n >> m;
	int min= n < m ? n : m,max= n>m ? n : m;
	int* c = new int[max+1], * a = new int[max], * b = new int[max];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}
	for (int i = min; i<max; ++i)
	{
		if (n > m)
		{
			b[i] = 0;
		}
		else
		{
			a[i] = 0;
		}
	}
	for (int i = 0; i < max; ++i)
	{
		int temp = a[i] + b[i] + out;
		c[i] = temp > 9 ? temp - 10:temp;
		out= temp > 9 ? 1 : 0;
	}
	c[max] = out;
	int k;
	for ( k = max;  k>= 0;k --)
	{
		if (c[k] != 0)
			break;
	}
	while (k >= 0)
	{
		cout << c[k];
		--k;
	}
}