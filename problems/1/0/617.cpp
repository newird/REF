#include <iostream>
using namespace std;

int main() {
	long long a;
	cin >> a;
	if (a < 1) {
		cout << -1;
		return -1;
	}
	cout << (1 + a) * a / 2;
	return (1 + a) * a / 2 ;
}