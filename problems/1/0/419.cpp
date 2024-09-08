#include<iostream>
using namespace std;
int main() {
	int a = 0;
	unsigned b = 0;
	cin >> a;
	if (a <= 0) { cout << -1; }
	else {
		for (int i = 0; i <= a; i++) { b += i; }
		cout << b;
	}
	return 0;
}