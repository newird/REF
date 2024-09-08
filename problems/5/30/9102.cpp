#include<iostream>

using namespace std;

void MaxHappiness(int a[], int last, int n, int index, int& result,int d,int m) {
	int increase = (a[index] - (index - last) * d);
	if (index == n) return;
	if (increase >= 0) {
		m -= 1;
		result += increase;
		MaxHappiness(a, index, n, index + 1, result, d, m);
	}
	else {
		MaxHappiness(a, last, n, index + 1, result, d, m);
	}
}

int main() {
	int n, m, d;
	cin >> n >> m >> d;
	int *a = new int[n];
	int result = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	MaxHappiness(a, -1, n, 0, result, d, m);
	cout << result;
	return 0;
}