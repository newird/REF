#include <iostream>
#include <vector>
#include <algorithm>

long long maxHappiness(int n, int m, int d, std::vector<int>& a) {
    // dp[i][j] 表示前 i 天使用了 j 次机会时的最大幸福值
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j]; // 不去看电影

            for (int k = 1; k <= i; ++k) {
                if (j >= 1) {
                    dp[i][j] = std::max(dp[i][j], dp[i - k][j - 1] + std::accumulate(a.begin() + i - k, a.begin() + i, 0) - d * (k - 1));
                }
            }
        }
    }

    return dp[n][m];
}

int main() {
    int n, m, d;
    std::cin >> n >> m >> d;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long answer = maxHappiness(n, m, d, a);
    std::cout << answer << std::endl;

    return 0;
}
