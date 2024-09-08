#include<iostream>

using namespace std;


int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int dp = 0, _min = a[0];
	for (int i = 0; i < n; i++)
	{
		_min = min(_min, a[i]);
		dp = max(dp, a[i] - _min);
	}
	cout << dp;
}