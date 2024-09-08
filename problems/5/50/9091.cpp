#include<iostream>
using namespace std;
int T[200005];

int mymax(int a, int b) {
	return a > b ? a : b;
}

void addT(int* T, int l, int n) {
	if (n == 0) {
		T[0] = l;
		return;
	}
	T[n] = l;
	for (int i = n; i >= 0 && T[i] < T[(i - 1) / 2]; i = (i - 1) / 2) {
		int copy = T[i];
		T[i] = T[(i - 1) / 2];
		T[(i - 1) / 2] = copy;
	}
	return;
}

void adjT(int* T, int l, int m) {
	for (int i = 0; i < m && (T[i] > T[2 * i + 1] || T[i] > T[2 * i + 2]); ) {
		if (T[i] > T[2 * i + 1]) {
			int copy = T[2 * i + 1];
			T[2 * i + 1] = T[i];
			T[i] = copy;
			i = 2 * i + 1;
		}
		else {
			int copy = T[2 * i + 2];
			T[2 * i + 2] = T[i];
			T[i] = copy;
			i = 2 * i + 2;
		}
	}
	return;
}


int main() {
	int n, m, d;
	cin >> n >> m >> d;
	int mysum = 0, mynum = 0, myans = -1;
	for (int i = 0; i < n; i++) {
		int l;
		cin >> l;
		if (l > 0) {
			mynum++;
			if (mynum <= m) {
				mysum += l;
				myans = mymax(myans, mysum - d * (i + 1));
				addT(T, l, mynum - 1);
			}
			else {
				mynum = m;
				mysum = mysum - T[0] + l;
				myans = mymax(myans, mysum - d * (i + 1));
				if (l > T[0]) {
					adjT(T, l, m);
				}
			}
		}
	}
	cout << mymax(myans, 0);
	return 0;
}