#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int digit = max(n, m);
    int* an = new int[digit + 1];
    int* am = new int[digit + 1];
    int* res = new int[digit + 1];
    for(int i = 0; i < digit + 1; ++i)
    {
        res[i] = 0;
        an[i] = 0;
        am[i] = 0;
    }
    for(int i = 0; i < n; ++i)
        cin >> an[i];
    for(int i = 0; i < m; ++i)
        cin >> am[i];
    int carry = 0;
    for(int i = 0; i < digit + 1; ++i)
    {
        int temp = an[i] + am[i] + carry;
        if(temp >= 10)
            carry = 1;
        else
            carry = 0;
        res[i] = temp % 10;
    }
    if(res[digit] != 0)
        cout << res[digit];
    for(int i = digit - 1; i >= 0; --i)
        cout << res[i];
    cout << endl;
    return 0;
}