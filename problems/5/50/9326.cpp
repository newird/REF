#include<iostream>
using namespace std;
using namespace std;
int day,times,down;
int val[200001]; int *dp;
int ans = 0;
void dfs(int nowtimes, int last, int sum)
{
	if (nowtimes == 0||sum<dp[last*(times+1)+nowtimes])return;
	else
	{
		for (int i = last + 1; i <= day; i++)
		{
			int get_val = val[i] - (i - last) * down;
			dp[i*(times+1)+nowtimes] = max(dp[i*(times + 1) + nowtimes], sum + get_val);
			sum += get_val; nowtimes--;
			ans = max(ans, sum);
			dfs(nowtimes, i, sum);
			sum -= get_val; nowtimes++;
		}
	}
}
int main()
{
	cin >> day >> times >> down; 
	for (int i = 1; i <= day; i++) 
	{ 
		cin >> val[i]; 
	} 
	dp = new int[(day + 1) * (times + 1)];
	for (int i = 0; i < (day + 1) * (times + 1); i++)
	{
		dp[i] = 0;
	}
	dfs(times, 0, 0);
	cout << ans;
}