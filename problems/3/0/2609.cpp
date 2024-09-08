#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int max = (n > m) ? n : m;
	int num_n[max + 1] = {0}, num_m[max + 1] = {0};
	for (int i = 0; i < n; i++) {
		cin >> num_n[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> num_m[i];
	}
	int res[max + 1];
	res[0] = num_n[0] + num_m[0];
	for (int i = 1; i < max; i++) {
		res[i] = num_n[i] + num_m[i] + (num_n[i - 1] + num_m[i - 1]) / 10;
	}

	for (int i = max - 1; i >= 0; i--) {
		if (i < max || res[i] != 0)
			cout << res[i];
	}
	return 0;

}