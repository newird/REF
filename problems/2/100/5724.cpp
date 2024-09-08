#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
    int n, k;
    cin >> n;
    vector<pair<int, int>> m;
    int Min = INT32_MAX;
    int res = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> k;
        Min = min(Min, k);
        res = max(res, k - Min);
    }
    cout << res;
    return 0;
}