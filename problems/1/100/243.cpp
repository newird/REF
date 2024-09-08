#include <iostream>
using namespace std;

int main(void)
{
    long long n;
    cin >> n;
    if (n < 1)
    {
        cout << "-1" << endl;
    }
    else
    {
        long long res = n * (n + 1) / 2;
        cout << res << endl;
    }
    return 0;
}