#include<iostream>
using namespace std;
int main() {
	int x;
	cin >> x;
	if (x < 1)
		cout << -1;
	else
	{
		long long int y;
		y = x * (x + 1) / 2;
		cout << y;
	return 0;
}