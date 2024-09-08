#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxProfit(vector<int>& prices) {
    int ans = 0;
    int n = prices.size();
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++ j)
        ans = max(0, prices[i] - prices[j]);
    }
    return ans;
}

int main()
{
    vector<int> price;
    int n;
    int tmp = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        price.push_back(tmp);
    }
    cout << maxProfit(price);
    return 0;
}