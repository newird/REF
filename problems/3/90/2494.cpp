#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	char* num1 = new char [n + 1] {};
	char temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		num1[i] = temp - '0';
	}
	char* num2 = new char [m + 1] {};
	for (int i = 0; i < m; i++) {
		cin >> temp;
		num2[i] = temp - '0';
	}
	if (m > n) {
		swap(n, m);
		swap(num1, num2);
	}
	char* result = new char[n + 1] {};
	int i = 0;
	for (; i < m; i++) {
		result[i] += num1[i] + num2[i];
		if (result[i] > 9) {
			result[i] -= 10;
			result[i + 1]++;
		}
	}
	for (; i < n; i++) {
		result[i] += num1[i];
		if (result[i] > 9) {
			result[i] -= 10;
			result[i + 1]++;
		}
	}
	bool start{};
	for (int i = n; i >= 0; i--) {
		if (start) {
			cout << (char)(result[i] + '0');
		} else {
			if (result[i] != 0) {
				start = true;
				cout << (char)(result[i] + '0');
			}
		}
	}

	return 0;
}
