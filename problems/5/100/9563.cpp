#include<iostream>
using namespace std;
int a[200010],x[200010]; long long int n, d, m;
long long int ans = 0; int len = 0;
long long int getmin(int x[])
{
	long long int minnum = 2000000000, index = 0;
	for (int i = 1; i <= len; i++)
	{
		if (x[i] < minnum)
		{
			minnum = x[i]; index = i;
		}
	}
	x[index] = 2000000000;
	return minnum;
}
int main()
{
	cin >> n >> m >> d; 
	long long int sum = 0, nowtimes = 0;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > 0)
		{
			len++; x[len] = a[i];
			if (nowtimes == m)
			{
				sum += (a[i] - getmin(x));
			}
			else
			{
				nowtimes++; sum += a[i];
			}
			ans = max(ans, sum - d * i); 
		}
	}
	cout << ans << endl;
	return 0;
}