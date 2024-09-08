#include <iostream>
using namespace std;
int main() {
	long long n = 0;
	cin >> n;
	long long sum = 0;
	if (n < 1) {
		cout << "-1";
		return -1;
	}
	for (long long i = 1;i <= n;i++) {
		sum += i;
	}
	cout << sum;
	return 0;

}