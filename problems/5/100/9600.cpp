#include<iostream>
#include<queue>
#include<functional>
#include<algorithm>

using namespace std;
//int T[200005];

int mymax(int a, int b) {
	return a > b ? a : b;
}

void addT(int* T, int l, int n) {
	if (n == 0) {
		T[0] = l;
		return;
	}
	int i = n;
	int j = n;
	while (i > 0 && l < T[(i - 1) / 2]) {
		T[i] = T[(i - 1) / 2];
		j = i;
		i = (i - 1) / 2;
	}
	if (T[i] < l) T[j] = l;
	else T[i] = l;
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

//小顶堆
priority_queue <long, vector<long>, greater<long> > sheap;

int main() {
	long n, m, d;
	cin >> n >> m >> d;
	long mysum = 0, mynum = 0, myans = -1;
	for (long i = 0; i < n; i++) {
		long happyness;
		cin >> happyness;
		if (happyness > 0) {
			mynum++;
			if (mynum <= m) {
				mysum += happyness;
				myans = max(myans, mysum - d * (i + 1));
				//addT(T, l, mynum - 1);
				//-------------------------------------
				sheap.push(happyness);
				//-------------------------------------
			}
			else {				
				//------------------------------------
				//int selem = T[0];

				int selem = sheap.top();
				
				//-----------------------------------
				mynum = m;
				myans = max(myans, mysum - selem + happyness - d * (i + 1));
				if (happyness > selem) {
					//adjT(T, l, m);
					//----------------------------------------------
					sheap.pop();
					sheap.push(happyness);
					//----------------------------------------------
					mysum = mysum - selem + happyness;
				}

			}
		}
	}
	cout << mymax(myans, 0);
	return 0;
}