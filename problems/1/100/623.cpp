#include<iostream>
using namespace std;
int main()
{
	int a;
	cin >> a ;
	long long s=0;
	if (a < 1)
		cout << -1;
	else
	{
		for (int i = 1; i <= a; i++)
		{
			s += i;
		}
		cout << s;
	}

	return 0;
}