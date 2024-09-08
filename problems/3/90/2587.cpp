#include<iostream>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	int len = m > n ? m + 1 : n + 1;
	int* data = new int[len];
	bool carry = false;
	int cur = 0,i;
	for ( i = 0; i < len; i++) {
		data[i] = 0;
	}
	for ( i = 0; i < m; i++) {
		cin >> data[i];
	}
	for ( i = 0; i < n; i++) {
		cin >> cur;
		data[i] = data[i] + cur + carry;
		carry = data[i] > 9;
		data[i] %= 10;
	}
	for (; i < len; i++) {
		data[i] += carry;
		carry = data[i] > 9;
		data[i] %= 10;
	}
	bool clear = false;
	for (int i = len - 1; i >= 0; i--) {
		if (data[i])
			clear = true;
		if (clear)
			cout << data[i];
	}
	return 0;
}