#include<iostream>
using namespace std;if(a[
}
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = i; j < n; j++) {
			if(a[j]<=a[i])
				continue;
			int temp = a[j] - a[i];
			max = max < temp ? temp : max;
		}
	}
	max = max > 0 ? max : 0;
	cout << max << endl;
	return 0;
}