#include <iostream>
using namespace std;
int main()
{
	long long int n;
	cin >> n;
	if (n < 1)
		cout << -1;
	else
		cout << ((1 + n) * n) / 2;
	return 0;
}