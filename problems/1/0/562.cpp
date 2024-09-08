#include <iostream>
using namespace std;

int f(int n)
{
	int sum = 0;
	if (n < 1)
		return -1;
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			sum += i;
		}
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;
	cout << f(n);
        return 0;
}