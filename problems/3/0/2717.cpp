#include<iostream>
using namespace std;

int bida(int a, int b)
{
	if (a > b)return a;
	else return b;
}

int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	int a[10];
	int b[10];
	int c = bida(n, m);
	int ans[10];
	for (int l = 0; l < c; l++) {
		a[l] = 0;
		b[l] = 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < m; j++) {
		cin >> b[j];
	}

	for (int k = 0; k < c; k++) {
		ans[k] = a[k] + b[k];
	}

	for (int k = c-1; k >=0; k--) {
		if (ans[k] != 0) {
			cout << ans[k];
		}
	}
	return 0;
}