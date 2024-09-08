#include <iostream>
using namespace std;
int ans = 0;
int n, m, d;
int lst[200005];
void backtrace(int pos,int cur_sum,int cnt)
{
	if(cnt<m)
	{
		if (cur_sum + lst[pos]-d > ans)
			ans = cur_sum + lst[pos]-d;
		if (pos + 1 < n)
		{
			backtrace(pos + 1, cur_sum + lst[pos]-d, cnt + 1);
			backtrace(pos + 1, cur_sum-d , cnt);
		}
	}
}
int main()
{
	cin >> n >> m >> d;
	for (int i = 0; i < n; ++i)
	{
		cin >> lst[i];
	}
	backtrace(0,0,0);
	cout << ans;
	return 0;
}
