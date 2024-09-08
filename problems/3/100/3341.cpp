#include<iostream>
using namespace std;
int main()
{
    int n,m;
    int a[100000],b[100000],c[100000];
    int jinwei = 0;
    bool nbigger = true;
    cin>>n>>m;
    if (n < m) nbigger = false;
    for (int i = 1;i <= n;i++) cin>>a[i];
    for (int i = 1;i <= m;i++) cin>>b[i];
    if (nbigger)
    {
        for (int i = 1;i <= m;i++) 
        {
            c[i] = a[i] + b[i] + jinwei;
            jinwei = c[i] / 10;
            c[i] = c[i] % 10;
        }
        for (int i = m+1;i <= n;i++) 
        {
            c[i] = a[i] + jinwei;
            jinwei = c[i] / 10;
            c[i] = c[i] % 10;
        }
        if (jinwei != 0) {n++; c[n] = jinwei;}
    }
    else
    {
        for (int i = 1;i <= n;i++)
        {
            c[i] = a[i] + b[i] + jinwei;
            jinwei = c[i] / 10;
            c[i] = c[i] % 10;
        }
        for (int i = n+1;i <= m;i++)
        {
            c[i] = b[i] + jinwei;
            jinwei = c[i] / 10;
            c[i] = c[i] % 10;
        }
        if (jinwei != 0) {m++; c[m] = jinwei;}
    }
    if (nbigger)
        for (int i = n;i >= 1; i--) cout<<c[i];
    else
        for (int i = m;i >= 1; i--) cout<<c[i];

    
    return 0;
}