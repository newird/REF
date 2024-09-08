#include<iostream>
using namespace std;
int day,times,down;
int val[200001];
int ans = 0;
void dfs(int nowtimes, int last, int sum)
{
	ans = max(ans, sum);
	if (nowtimes == 0)return;
	else
	{
		for (int i = last + 1; i <= day; i++)
		{
			int get_val = val[i] - (i - last) * down;
			sum += get_val; nowtimes--;
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
	dfs(times, 0, 0);
	cout << ans;
}