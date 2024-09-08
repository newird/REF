#include <iostream>
using namespace std;

int main()
{
	long long int N;
	cin >> N;
	if (N < 1)
		cout << "-1";
	else
	{
		long long int result = (1 + N) * N / 2;
		cout << result;
	}
	return 0;
}