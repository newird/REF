#include<iostream>
using namespace std;
int main() {
	int n, a[100000];
	cin >> n;
	int i = 0;
	int min, max;
	int w = 0;
	while (i < n) {
		cin >> a[i];
		i++;
	}
	min = 0;
	max = 0;
	i = 1;
	while (i < n) {
		if (a[i] < a[min]) {
			min = i;
			if (min > max)
				max = min;
		}
		if (a[i] > a[max]) {
			max = i;
			if (a[max] - a[min] > w)
				w = a[max] - a[min];
		}
		i++;
	}
	cout << w;
	return 0;
}
