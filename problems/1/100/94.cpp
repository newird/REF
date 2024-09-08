#include<iostream>
using namespace std;
int main()
{
	 long long int n;
	cin >>n;
	if (n < 1)
		cout << -1;
	else
	{
		long long int ans = 0;
		for (int i = 1; i <= n; i++)
			ans += i;
		cout << ans;
	}

	
}