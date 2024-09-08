#include <iostream>
using namespace std;

int main()
{
	int n;
	int sum = 0;
	cin >> n;
	if (n < 1)
		cout << -1;
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			sum += i;
		}
		cout << sum;
	}
	return 0;
}