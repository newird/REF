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

    vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    dp[0][0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 1; k <= min(j, i); k++) {
                if (dp[i - k][j - k] != -1) {
                    int gap = i - (i - k);
                    int decrease = d * gap;
                    dp[i][j] = max(dp[i][j], dp[i - k][j - k] + happiness[i] - decrease);
                }
            }
        }
    }

    int maxHappiness = 0;
    for (int j = 0; j <= m; j++) {
        maxHappiness = max(maxHappiness, dp[n - 1][j]);
    }

    cout << maxHappiness << endl;

    return 0;
}