#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int* p;
	p = new int[n];
	int* q;
	q = new int[m];

	for (int i = 0; i < n; i++)cin >> p[i];
	for (int i = 0; i < m; i++)cin >> q[i];

	int sum_n = 0;
	for (int i = n - 1; i >= 0; i--)sum_n = 10 * sum_n + p[i];
	int sum_m = 0;
	for (int i = m - 1; i >= 0; i--)sum_m = 10 * sum_m + q[i];

	cout << sum_n + sum_m;

	delete[]p;
	delete[]q;

	return 0;
}