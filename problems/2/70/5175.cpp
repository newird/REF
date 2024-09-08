#include<iostream>
using namespace std;

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int min(int a, int b) {
	if (a > b)
		return b;
	return a;
}

int main() {
	int n;
	cin >> n;
	int* P = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> P[i];
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > i) {
				result = min(P[i] - P[j], result);
			}
		}
	}
	cout << -result;
	return 0;
}