#include<cmath>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<vector>

using namespace std;




int num[10001];
int dp[10001];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	stack<int>st;
	int temp = 0;
	for (int i = n-1; i >= 0; --i)
	{
		temp = max(temp, num[i]);
		dp[i] = temp;
	}
	int out = 0;
	for (int i = 0; i < n; ++i)
	{
		out = max(dp[i] - num[i], out);
	}
	cout << out;
}