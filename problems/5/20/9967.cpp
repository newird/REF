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

    sort(happiness.begin(), happiness.end());

    vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + happiness[i - 1];
    }

    vector<long long> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = RAND_MAX;
        for (int j = max(0, i - m); j < i; j++) {
            dp[i] = min(dp[i], dp[j] + d * (i - j - 1) - (prefixSum[i] - prefixSum[j]));
        }
    }
    if(dp[n]>0){
    cout << dp[n] << endl;
    }else{
        cout<<0<<endl;
    }
    return 0;
}