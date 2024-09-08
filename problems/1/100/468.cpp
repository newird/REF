#include <iostream>
#include <cstring>
using namespace std;
long long n,result;

int main()
{
	cin >> n;
	result = n * (n + 1) / 2;
	if (n < 1)
	{
		cout << -1;
	}
	else {
		cout << result;
	}
}