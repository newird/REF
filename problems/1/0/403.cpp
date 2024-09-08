#include <iostream>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	if (n < 1) {
		
		return -1;
	}
	long long sum = 0;
	int i = 0;
	for (i = 1;i <= n;i++) {
		sum = sum + i;		
	}
	cout << sum;
	return 0;

}