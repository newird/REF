#include <iostream>
using namespace std;

int Total(long long x)
{
	long long y = 0;
	if (x < 1)
	{
		return -1;
	}

	else
	{
		for (int i = 1; i <= x; i = i + 1)
		{
			y = y + i;
		}
	}

	return y;
}

int main()
{
	long long a, b;
	cin >> a;
	b = Total(a);
	cout << b;
	return 0;
}