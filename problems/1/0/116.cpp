#include <iostream>
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	long long sum = 0;
	if (n < 1)
		return -1;
	for (int i = 1;i <= n;i++) {
		sum += i;
	}
	cout << sum;
	return 0;

}