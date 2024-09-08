#include <iostream>
using namespace std;
int main() {
	long long N = 0;
	long long sum = 0;
	cin >> N;
	if (N < 1)
		cout << -1;
	else {
		while (N > 0) {
			sum = sum + N;
			N--;
		}
		cout << sum;
	}
}