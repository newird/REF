#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int m,n;
	cin >> m >> n;
	int* p = new int[m];
	int* q = new int[n];
	for (int i = 0; i < m; i++)
	{
		cin >> p[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> q[i];
	}
	int max_0 = max(m, n);
	int min_0 = min(m, n);
	int* ans = new int[max_0+1];
	int k1 = m-1, k2 = n-1;
	int cf = 0;
	for (int i = 0; i < min_0; i++)
	{
		ans[i] = (p[i] + q[i] + cf) % 10;
		cf= (p[i] + q[i] + cf) / 10;
	}
	if (m>n)
	{
		for (int i = n; i < m; i++)
		{
			ans[i] = (p[i] + cf) % 10;
			cf = (p[i] + cf) / 10;
		}
	}
	else if (m<n)
	{
		for (int i = m; i < n; i++)
		{
			ans[i] = (q[i] + cf) % 10;
			cf = (q[i] + cf) / 10;
		}
	}
	if (cf)
		cout << 1;
	for (int i = max_0-1; i >= 0; i--) {
		cout << ans[i];
	}
	return 0;
}