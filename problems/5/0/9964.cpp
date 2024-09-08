#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> happiness(n);
    for (int i = 0; i < n; i++) {
        cin >> happiness[i];
    }

    // 对观看每部电影后的幸福值进行排序
    sort(happiness.begin(), happiness.end());

    // 计算总幸福值
    long long totalHappiness = 0;
    for (int i = 0; i < n; i++) {
        totalHappiness += happiness[i];
    }

    // 计算需要的等待天数
    vector<long long> waitDays(n, 0);
    for (int i = 1; i < n; i++) {
        waitDays[i] = waitDays[i-1] + d;
    }

    // 如果可以观看的次数大于等于电影天数，输出总幸福值
    if (m >= n) {
        cout << totalHappiness << endl;
        return 0;
    }

    // 动态规划求解最大幸福值
    vector<long long> dp(n, 0);
    for (int i = 0; i < n; i++) {
        dp[i] = totalHappiness;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i - j < 0) {
                dp[i] = max(dp[i], totalHappiness);
            } else {
                dp[i] = max(dp[i], dp[i - j] - waitDays[j]);
            }
        }
    }

    cout << dp[n - 1] << endl;
    return 0;
}