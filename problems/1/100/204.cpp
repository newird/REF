#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	if (N < 1) 	cout << -1;

	else {
		long long r = N;
		while (N--) {
			r += N;
		}
		cout << r;
	}

	return 0;

}