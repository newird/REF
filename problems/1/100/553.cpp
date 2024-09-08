#include <iostream>

using namespace std;

int main()
{

    int a ;
    cin >> a ;
    long long int s = 0;
    if (a < 1)s = -1;
    else
    {
        for (; a > 0; --a)
            s = s + a;
    }



    cout <<s;
    return 0;
}