#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    long long int a,b;
    cin >> a ;
    b = 0;
    if (a < 0) { cout << -1; }
    if (a == 0) { cout <<0; }
    if (a > 0)
    {
        for (int i = 1; i <= a; i++)
        {
            b = b + i;
        }
        cout << b;
    }

    return 0;
}