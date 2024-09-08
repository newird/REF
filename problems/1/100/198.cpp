#include<iostream>
using namespace std;
int main() {
	long long int a = -1;
	cin >> a;
	if (a < 1) {
		cout << "-1";
	}
	else
	{
		cout << a * (a + 1) / 2;
	}
	return 0;
}