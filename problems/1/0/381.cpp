#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	if (a <= 0){
		cout << -1;
		return -1;
	}
	long long result = 0;
	for (int i = 1; i <= a; i++) {
		result += i;
	}
	cout << result;
}