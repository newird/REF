#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& p) {
    int valley = INT8_MAX;
    int ans = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] < valley) {
            valley = p[i];
        }
        else if (p[i] - valley > ans) {
            ans = p[i] - valley;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    vector<int> ex;

    while (t--) {
        int n;
        cin >> n;
        ex.push_back(n);
    }

    cout << maxProfit(ex) << endl;
    return 0;
}

