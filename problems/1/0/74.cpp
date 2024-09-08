#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >>n;
	if (n < 1)
		cout << -1;
	else
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans += i;
		cout << ans;
	}

	
}