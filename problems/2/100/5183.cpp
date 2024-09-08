#include<iostream>
#include<stack>
#include<algorithm>
#include<string.h>
using namespace std;
int n; int value[100001];
stack<int>s;
int main()
{
	cin >> n;
	int ans = 0; value[0] = 100000000;
	for (int i = 1; i <= n; i++)
	{
		cin >> value[i];
	}
	s.push(0);
	for (int i = 1; i <= n; i++)
	{
		if (value[i] < value[s.top()])
		{
			s.push(i); continue;
		}
		else
		{
			ans = max(ans, value[i] - value[s.top()]);
		}
		
	}
	cout << ans;
}