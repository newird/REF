#include <iostream>
using namespace std;
int main() {
	long long a;
	cin >> a;
	if (a < 1) {
		cout << -1;
		return -1;
	}
	long long result = 0;
	for (long long i = 1; i <= a; i++) {
		result = result + i;
	}
	cout << result;
}