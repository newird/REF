#include<iostream>
using namespace std;
int a[200010]; long long int n, d, m;
long long int ans = 0;
int main() 
{    
	cin >> n >> m >> d;     
	long long int sum = 0, nowtimes = 0, last = 0; a[0] = 2000000000;
	long long int min1 = 2000000000,min1_index=0;
	long long int min2 = 2000000000, min2_index = 0;
	for (long long int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > 0)
		{
			if (a[last] < min1)
			{
				min1 = a[last];
				min1_index = last;
			}
			else if (a[last] < min2)
			{
				min2 = a[last];
				min2_index = last;
			}
			if (nowtimes == m)
			{
				sum += (a[i] - min1);
				min1 = min2; min1_index = min2_index;
			}
			else
			{
				nowtimes++; sum += a[i];
			}
			ans = max(ans, sum - d * i); last = i;
		}
	}
	cout << ans << endl;       
	return 0;
}