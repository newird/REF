#include<iostream>
using namespace std;
int main() {
	int x;
	cin >> x;
	if (x < 1)
		cout << -1;
	else
	{
		long long int y=0;
		for (int i = 1; i <= x; i++)
			y += i;
		cout << y;
	}
	return 0;
}