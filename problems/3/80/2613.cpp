#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int* a = new int[n];
	int* b = new int[m];
	for (int i = 0; i != n; i++)
		cin >> a[i];
	for (int i = 0; i != m; i++)
		cin >> b[i];
	if (n == m)
	{
		int* c = new int[n + 1];
		int cf = 0;
		for (int i = 0; i != n; i++)
		{
			c[i] = a[i] + b[i] + cf;
			if (c[i] >= 10)
			{
				c[i] %= 10;
				cf = 1;
			}
			else
				cf = 0;
		}
		if (cf == 1)
		{
			c[n] = 1;
			for (int i = 0; i != n + 1; i++)
				cout << c[n - i];
		}
		else
			for (int i = 1; i != n + 1; i++)
				cout << c[n - i];
		return 0;
	}
	else
	{
		int max, min;
		if (n > m)
		{
			max = n;
			min = m;
		}
		else
		{
			max = m;
			min = n;
		}
		int* c = new int[max + 1];
		int cf = 0;
		for (int i = 0; i != min; i++)
		{
			c[i] = a[i] + b[i] + cf;
			if (c[i] >= 10)
			{
				c[i] %= 10;
				cf = 1;
			}
			else
				cf = 0;
		}
		if (cf == 1)
		{
			if (n > m)//a is larger
			{
				for (int i = min; i != max; i++)
				{
					c[i] = a[i] + cf;
					if (c[i] >= 10)
					{
						c[i] %= 10;
						cf = 1;
					}
					else
						cf = 0;
				}
				c[max] = 1;
			}
			else
			{
				for (int i = min; i != max; i++)
				{
					c[i] = b[i] + cf;
					if (c[i] >= 10)
					{
						c[i] %= 10;
						cf = 1;
					}
					else
						cf = 0;
				}
				c[max] = 1;
			}
			for (int i = 0; i != max; i++)
				cout << c[max - i - 1];
			return 0;
		}
		else
		{
			if (n > m)//a is larger
			{
				for (int i = min; i != max; i++)
					c[i] = a[i];
			}
			else
			{
				for (int i = min; i != max; i++)
					c[i] = b[i];
			}
			for (int i = 0; i != max; i++)
				cout << c[max - i - 1];
			return 0;
		}
	}
}