#include <iostream>
#include <queue>
using namespace std;

int main() {
	long long happiness = 0;
	int n, m;
	long long d;
	cin >> n >> m >> d;
	long long a[n + 2];
	long long dp[n + 2] {};
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a[i] = temp;
	}
	priority_queue<long long,vector<long long>,std::greater<long long>> q;
	long long sum{};
	for (int i = 0; i < n; i++) {
		if (q.size() < m) {
			if (a[i] > 0) {
				q.push(a[i]);
				sum += a[i];
			}
		} else {
			if (a[i] > q.top()) {
				long long temp = q.top();
				q.pop();
				q.push(a[i]);
				sum -= temp;
				sum += a[i];
			}
		}
		dp[i] = sum;
	}
	for (int i = 0; i < n; i++) {
		if (dp[i] - d * (i + 1) > happiness) {			//一定是选择前面的较大的m（或少于m）个数
			happiness = dp[i] - d * (i + 1);
		}
	}
	cout << happiness;

	return 0;
}