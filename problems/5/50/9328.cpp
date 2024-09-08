#include<iostream>
using namespace std;
int day,times,down;
int val[200001]; int dp[200001];
int ans = 0;
void dfs(int nowtimes, int last, int sum)
{
	if (nowtimes == 0 || sum < dp[last])return;
	for (int i = last + 1; i <= day; i++)
	{
			int get_val = val[i] - (i - last) * down;
			dp[i] = max(dp[i], sum + get_val);
			sum += get_val; nowtimes--;
			ans = max(ans, sum);
			dfs(nowtimes, i, sum);
			sum -= get_val; nowtimes++;
	}
}
int main()
{
	cin >> day >> times >> down; 
	for (int i = 1; i <= day; i++) 
	{ 
		cin >> val[i]; 
	} 
	dfs(times, 0, 0);
	cout << ans;
}