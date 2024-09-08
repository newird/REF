#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	int ans = 0, sum = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		if (t > 0)
		{
			if (q.size() >= m)
			{
				sum -= q.top();
				t = max(t, q.top());
				q.pop();
			}
			q.push(t);
			sum += t;
		}
		ans = max(ans, sum - i * d);
	}
	cout << ans << endl;
	return 0;
}