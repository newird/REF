#include <iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;

	if (n < 1)cout << -1;
	else {
		long long r = n;
		while (n--) {
			r += n;
		}
		cout << n;
	}

	return 0;

}