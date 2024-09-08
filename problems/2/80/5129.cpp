#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n;
    vector<int> m;
    for(int i = 0; i < n; ++i)
    {
        cin >> k;
        m.push_back(k);
    }
    int res = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i; j < n; ++j)
        {
            res = max(res, m[j] - m[i]);
        }
    }
    cout << res;
  
    return 0;
}