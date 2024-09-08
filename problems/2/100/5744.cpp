#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* price = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> price[i];
	}
	int** money = new int*[2];
	money[0] = new int[n];
	money[1] = new int[n];

	money[0][0] = 0;
	money[1][0] = -price[0];

	for (int i = 1; i < n; ++i) {
		if (money[0][i - 1] > money[1][i - 1] + price[i])
			money[0][i] = money[0][i - 1];
		else
			money[0][i] = money[1][i - 1] + price[i];
		if (money[1][i - 1] > -price[i])
			money[1][i] = money[1][i - 1];
		else
			money[1][i] = -price[i];
	}

	int m;
	if (money[1][n - 1] > money[0][n - 1])
		m = money[1][n - 1];
	else
		m = money[0][n - 1];
	cout << m;
	return 0;
}