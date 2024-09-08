#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main()
{
    int maxmoney = 0;
    int input;
    int n;
    cin >> n;
    stack<int> data;
    for (int i = 0; i < n-1; i++)
    {
        cin >> input;
        if (data.empty())
        {
            data.push(input);
        }
        else
        {
            int current = data.top();
            maxmoney = (maxmoney >= input - current) ? maxmoney : input - current;
            if (input < current)
            {
                data.pop();
                data.push(input);
            }
        }
    }
    cin >> input;
    int current = data.top();
    maxmoney = (maxmoney >= input - current) ? maxmoney : input - current;
    cout << maxmoney;
    return 0;
}