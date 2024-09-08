#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int main()
{
	long long n, m, d;
	cin >> n >> m >> d;
	long long ans = 0, sum = 0;
	priority_queue<long long, vector<long long>, greater<long long>> q;
	for (long long i = 1; i <= n; i++)
	{
		long long t;
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