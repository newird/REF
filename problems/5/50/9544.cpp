#include<iostream>
using namespace std;
int a[200010]; int n, d, m;
int ans = 0;
int main() 
{    
	cin >> n >> m >> d;     
	int sum = 0,nowtimes=0,last=0;
	int minHap = 2000000000;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > 0)
		{
			minHap = min(minHap, a[i]);
			if (nowtimes == m)
			{
				sum += a[i] - minHap;
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