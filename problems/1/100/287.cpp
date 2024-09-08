#include <iostream>
using namespace std;
int main()
{
    long long int N,sum;
    cin >> N ;
    if(N<1)
        cout << -1 << endl;
    else
    {
        sum = (1 + N) * N / 2;
        cout << sum << endl;
    }
    return 0;
}
