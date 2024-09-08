#include <iostream>
using namespace std;

int Total(int x)
{
	int y = 0;
	while (x >= 0)
	{
		y = y + x;
		x = x - 1;
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