#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n < 1) {
		cout << -1;
	}else {
		int result = 0;
		while (n >= 1) {
			result += n;
			n--;
		}
		cout << result;
	}
	return 0;
}