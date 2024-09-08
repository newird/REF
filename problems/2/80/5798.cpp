#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxProfit(vector<int>& prices) {
    int ans = 0;
    int n = prices.size();
    for (int i = 0; i < n-1; ++i) {
        for(int j = i+1; j < n; ++j)
        ans = max(ans, prices[j] - prices[i]);
    }
    return ans;
}

int main()
{
    vector<int> price;
    int n;
    cin >> n;
    int tmp = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        price.push_back(tmp);
    }
    cout << maxProfit(price);
    return 0;
}