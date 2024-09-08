#include<iostream>
using namespace std;

int main() {
	int n = 0; int max = 0; int min = 0; int r = 0;
	cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);
	cin >> a[0];
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		if (a[i] > a[i - 1]) {
			max = i; r = (r < a[max] - a[min]) ? a[max] - a[min] : r;
		}
		else { min = (a[i] < a[min]) ? i : min; }
	}
	cout << r;
}