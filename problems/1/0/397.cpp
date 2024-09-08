#include<iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;
	if (a <= 0)
	{
		cout << -1;
		return 0;
	}
	else
	{
		int rst = 0;
		for (; a >= 1; a--)
			rst += a;
		cout << rst;
		return 0;
	}
}