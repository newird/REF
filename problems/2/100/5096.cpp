#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int Min{99999999}, Max{0}, temp{};
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp < Min) {
			Min = temp;
		} else {
			Max = std::max(Max, temp - Min);
		}
	}
	cout << Max;
	return 0;
}