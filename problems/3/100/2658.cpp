#include<iostream>
using namespace std;
int main()
{
    int m, n,s;
    cin >> n >> m;
    if(m>n)
        s = m;
    else
        s = n;
    int *a = new int[s];
    int *b = new int[s];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m;++i)
        cin >> b[i];
    if(m==n)
    {
        int *c = new int[n + 1],k=0;
        for (int i = 0; i < m;++i)
        {
            c[i] = (a[i] + b[i] + k) % 10;
            k=(a[i] + b[i] + k) / 10;
        }
        if(k!=0)
            cout << "1";
        for (int i = m - 1; i > -1;--i)
            cout << c[i];
    }
    else if(m<n)
    {
        int *c = new int[n + 1],k=0;
        for (int i = 0; i < n;++i)
        {
            if(i>=m)
                b[i] = 0;
            c[i] = (a[i] + b[i] + k) % 10;
            k = (a[i] + b[i] + k) / 10;
           
        }
        if (k != 0)
                cout << "1";
        for (int i = n - 1; i > -1;--i)
            cout << c[i];
    }
    else
    {
        int *c = new int[m + 1],k=0;
        for (int i = 0; i < m;++i)
        {
            if(i>=n)
                a[i] = 0;
            c[i] = (a[i] + b[i] + k) % 10;
            k = (a[i] + b[i] + k) / 10;
           
        }
        if (k != 0)
                cout << "1";
        for (int i = m - 1; i > -1;--i)
            cout << c[i];
    }

    return 0;
}