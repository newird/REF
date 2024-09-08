#include<iostream>
using namespace std;

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int main() {
	int n, m;
	cin >> n >> m;
	int* N = new int[n];
	int* M = new int[m];
	int* p = new int[max(m, n) + 1];
	for (int i = 0; i < n; i++) {
		cin >> N[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> M[i];
	}
	for (int i = 0; i <= max(m,n); i++) {
		p[i] = 0;
	}
	for (int i = 0; i <= max(m, n); i++) {
		if (i <= m - 1 && i <= n - 1) {
			if (M[i] + N[i] >= 10) {
				p[i] += M[i] + N[i] - 10;
				p[i + 1]++;
			}
			else {
				p[i] += M[i] + N[i];
			}
		}
		if (i >= m && i <= n - 1) {
			p[i] += M[i];
		}
		if (i >= n && i <= m - 1) {
			p[i] += N[i];
		}
		if (p[i] >= 10) {
			p[i] -= 10;
			p[i + 1]++;
		}
	}
	for (int i = max(m, n);i >= 0; i--) {
		if (i == max(m, n) && p[i] > 0) {
			cout << p[i];
		}
		else if (i == 0) {
			cout << p[i] << endl;
		}
		else if(i != max(m,n)) {
			cout << p[i];
		}
	}
	delete[] M;
	delete[] N;
	delete[] p;
	return 0;
}