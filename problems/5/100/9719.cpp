#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
long long T, n, m, d, a;
long long sum, ans;
priority_queue<long long, vector<long long>, greater<long long> >q;
int main()
{
	
	cin >> n >> m >> d;
	ans = sum = 0;
		for (long long i = 1; i <= n; ++i)
		{
			cin>>a;
			if (a < 0) continue;
			q.push(a);
			sum += a;
			if (q.size() > m) 
			{
				sum -= q.top();
				q.pop();
			}
			ans = max(ans, sum - d * i);
		}
		cout << ans;
		return 0;
	
}