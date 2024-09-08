#include<iostream>
using namespace std;

int main() {
	long long n = 0;
	cin >> n;
	if (n < 1) {
		cout << -1;
	}
	else {
		long long res = 0;
		while (n >= 1) {
			long long a = n;
			res += a;
			n--;
		}
		cout << res;
	}
	return 0;
}