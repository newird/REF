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
	int j = (n-1)/2;
	while (i > 0) {
		if (l >= T[j]) {  break; }
		else {
			T[i] = T[j];
			i = j;
			j = (j - 1) / 2;
		}
	} 
	T[i] = l;
	return;
}

void adjT(int* T, int l, int m) {
	int i = 0;
	while (2 * i + 1 < m) {
		if ((2 * i + 2 < m && l <= T[2 * i + 1] && l <= T[2 * i + 2]) || (2 * i + 2 == m && l <= T[2 * i + 1]))		break;
		else   if (2 * i + 1 < m && 2 * i + 2 >= m) {
			T[i] = T[2 * i + 1];
			i = 2 * i + 1;
		}
		else   if (T[2 * i + 1] < T[2 * i + 2]) {
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
	long long int mysum = 0;
	long long int mynum = 0;
	long long int myans = -1;
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