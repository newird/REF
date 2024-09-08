#include<iostream>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	int a[100000] = { 0 }, b[100000] = { 0 };
	int i = 0, j = 0;
	while (i < m) {
		cin >> a[i];
		i++;
	}
	while (j < n) {
		cin >> b[j];
		j++;
	}
	int c[100000] = { 0 }, x = m;
	if (n > m)
		x = n;
	i = 0;
	while (i < x) {
		c[i] = a[i] + b[i] + c[i];
		if (c[i] >= 10) {
			c[i] -= 10;
			c[i + 1]++;
		}
		i++;
	}
	if (c[x] == 1) {
		cout << 1;
		i = x - 1;
		while (i >= 0) {
			cout << c[i];
			i--;
		}
	}
	if (c[x] == 0) {
		i = x - 1;
		while (i >= 0) {
			if (c[i] == 0)
				i--;
			else
				break;
		}
		if (i == -1)
			cout << 0;
		while (i >= 0) {
			cout << c[i];
			i--;
		}
	}
	return 0;
}
