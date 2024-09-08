#include <iostream>
using namespace std;

int Total(int x)
{
	int y = 0;
	if (x <= 0)
	{
		y = -1;
	}

	else
	{
		for (int i = 0; i <= x; i = i + 1)
		{
			y = y + i;
		}
	}
	return y;
}

int main()
{
	int a, b;
	cin >> a;
	b = Total(a);
	cout << b;
	return 0;
}