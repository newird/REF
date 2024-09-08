#include <iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    if (n > m)
    {
        int* a = new int[n + 1];
        int* b = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
           a[i]=0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i <= n; i++)
        {
            b[i]=0;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < m; i++)
        {
            a[i] = a[i] + b[i];
            if (a[i] >= 10)
            {
                a[i] -= 10;
                a[i+1]++;
            }
        }
        if (a[n] != 0) 
        {
            for (int i = n; i >= 0; i--)
            {
                cout << a[i];
            }
        }
        else
        {
            for (int i = n-1; i >= 0; i--)
            {
                cout << a[i];
            }
        }
    }
    else
    {
        int* a = new int[m + 1];
        int* b = new int[m + 1];
        for (int i = 0; i <= m; i++)
        {
            a[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i <= m; i++)
        {
            b[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            b[i] = a[i] + b[i];
            if (b[i] >= 10)
            {
                b[i] -= 10;
                b[i+1]++;
            }
        }
        if (b[m] != 0)
        {
            for (int i = m; i >= 0; i--)
            {
                cout << b[i];
            }
        }
        else
        {
            for (int i = m - 1; i >= 0; i--)
            {
                cout << b[i];
            }
        }
    }
    return 0;
}
