#include<iostream>
using namespace std;
int a[100001], b[100001];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	for (int i = 1; i <= max(m, n); i++)
	{
		a[i] = a[i] + b[i];
		if (a[i] >= 10)
		{
			a[i] -= 10; a[i + 1]++;
		}
	}
	if (a[max(m, n) + 1])
	{
		for (int i = max(m, n) + 1; i >= 1; i--)
			cout << a[i];
	}
	else
		for (int i = max(m, n); i >= 1; i--)
			cout << a[i];

}