#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m, d;
	cin >> n >> m >> d;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m && j <= i; j++) {
			dp[i][j] = dp[i - 1][j]; // 不观看该电影
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i - 1]); // 观看该电影，但不计入幸福值
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i - 1] - d * (i - j)); // 观看该电影，并计入幸福值
		}
	}

	cout << (dp[n][m] > 0 ? dp[n][m] : 0);

	return 0;
}