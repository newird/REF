#include<iostream>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	if (n < 1) {
		cout << -1;
	}
	else {
		int res = 0;
		while (n >= 1) {
			int a = n;
			res += a;
			n--;
		}
		cout << res;
	}
	return 0;
}