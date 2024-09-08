#include <iostream>
using namespace std;

int Max(int n, int m) {
	if (n > m)
		return n;
	return m;
}

int main() {
	int n, m;
	cin >> n >> m;
	int len = Max(n, m) + 1;
	int* a = new int[n], * b = new int[m], * c = new int[len];//a、b为两个操作数，c存放计算结果
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < len; ++i) { //初始化c
		c[i] = 0;
	}
	if (n <= m) {
		for (int i = 0; i < n; ++i) {
			int t = a[i] + b[i] + c[i];
			if (t > 9) {
				c[i] = t - 10;
				c[i + 1]++;
			}
			else
				c[i] = t;
		}
		for (int i = n; i < m; ++i) {
			int t = b[i] + c[i];
			if (t > 9) {
				c[i] = t - 10;
				c[i + 1]++;
			}
			else
				c[i] = t;
		}
	}
	else {
		for (int i = 0; i < m; ++i) {
			int t = a[i] + b[i] + c[i];
			if (t > 9) {
				c[i] = t - 10;
				c[i + 1]++;
			}
			else
				c[i] = t;
		}
		for (int i = m; i < n; ++i) {
			int t = a[i] + c[i];
			if (t > 9) {
				c[i] = t - 10;
				c[i + 1]++;
			}
			else
				c[i] = t;
		}
	}
	for (int i = len - 1; i >= 0; --i) {
		if (i != len - 1 || (i == len - 1 && c[i] != 0))
			cout << c[i];
	}
	return 0;
}