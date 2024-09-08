#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* price = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> price[i];
	}
	int money = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (money < price[j] - price[i])
				money = price[j] - price[i];
		}
	}
	if (money < 0)
		cout << "0";
	else
		cout << money;
	return 0;
}