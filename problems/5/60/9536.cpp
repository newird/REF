#include <iostream>
#include <queue>
const long long inf = 0x7fffffffffffffff;
using namespace std;
int n, m, d, t;
long long q[200005], sum, ans;

priority_queue<long long, vector<long long>, greater<long long>> pq;

void qwq(long long x) {
	if (pq.size() < m) {
		sum += x;
		pq.push(x);
	}
	if (pq.size() == m && x > pq.top()) {
		sum += x - pq.top();
		pq.pop();
		pq.push(x);
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &d);
	q[0] = inf;
	long long x;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x);
		if (x > 0) {
			qwq(x);
			ans = max(ans, sum - d * i);
		}
	}
	printf("%lld", ans);
}