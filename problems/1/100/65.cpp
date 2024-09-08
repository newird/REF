#include <iostream>

using namespace std;


int main()
{
	long long int n;
	cin >> n;
	if (n < 1)
	{
		cout << -1;
		return 0;
	}
	cout << n * (n + 1) / 2;
}