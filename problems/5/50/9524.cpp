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
	int i = n;
	while (i > 0 && l < T[(i - 1) / 2]) {
		T[i] = T[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	T[i] = l;
	return;
}

void adjT(int* T, int l, int m) {
	int i = 0;
	while (i < m - 1 && (l > T[2 * i + 1] || l > T[2 * i + 2])) {
		if (T[2 * i + 1] < T[2 * i + 2]) {
			T[i] = T[2 * i + 1];
			i = 2 * i + 1;
		}
		else {
			T[i] = T[2 * i + 2];
			i = 2 * i + 2;
		}
	}
	T[i] = l;
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
				myans = mymax(myans, mysum - T[0] + l - d * (i + 1));
				if (l > T[0]) {
					adjT(T, l, m);
					mysum = mysum - T[0] + l;
				}

			}
		}
	}
	cout << mymax(myans, 0);
	return 0;
}