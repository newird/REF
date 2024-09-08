#include<iostream>
using namespace std;

int main()
{
	long long int a;
	cin >> a;
	if (a <= 0)
	{
		cout << -1;
		return 0;
	}
	else
	{
		long long int rst = 0;
		for (; a >= 1; a--)
			rst += a;
		cout << rst;
		return 0;
	}
}