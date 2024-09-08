#include <iostream>
#include <vector>
#include <climits> // INT_MAX

using namespace std;

int maxProfit(vector<int>& prices) {
    int valley = INT_MAX;
    int ans = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < valley) {
            valley = prices[i];
        }
        else if (prices[i] - valley > ans) {
            ans = prices[i] - valley;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> ex(n); 
        for (int i = 0; i < n; i++) {
            cin >> ex[i];
            if (ex[i] < 0 || ex[i] > 10000) {
                return 1;
            }
        }
        cout << maxProfit(ex) << endl;
    }

    return 0;
}