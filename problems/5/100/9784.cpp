#include<iostream>
#include<math.h>
using namespace std;
void shiftdown(long long int i, long long int k, long long int* a)
{
    long long int flag = 0, temp;
    long long int t = i;
    while (i * 2 + 1 < k && flag == 0)
    {
        if (a[2 * i + 1] < a[i])
            t = 2 * i + 1;
        if (2 * i + 2 < k)
        {
            if (a[2 * i + 2] < a[t])
                t = 2 * i + 2;
        }
        if (t != i)
        {
            temp = a[t];
            a[t] = a[i];
            a[i] = temp;
            i = t;
        }
        else
            flag = 1;
    }
}
long long int f(long long int* a, long long int n, long long int k)
{
   long long int c = 0, q = k, j, i,count=0;
    while (q != 1)
    {
        q /= 2;
        c++;
    }
    for (j = pow(2, c) - 2; j >= 0; j--)
    {
        shiftdown(j, k, a);
    }
    for (i = k; i < n; i++)
    {
        if (a[i] > a[0])
        {
            a[0] = a[i];
            shiftdown(0, k, a);
        }
    }
    for (i = 0; i < k; i++)
    {
        count += a[i];
    }
    return count;
}
int main()
{
	long long int n, m, d, i, j, s, count=0;
	cin >> n >> m >> d;
    long long int* a = new long long int[n];
    long long int* b = new long long int[m];
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
    long long int t=0, result=0,add=0;
    for (i = 0; i < n && t < m ; i++)
    {
        if (0 < a[i])
        {
            add += a[i];
            b[t] = i;
            t++;
            if (add - (i + 1) * d > result)
            {
                result = add - (i + 1) * d;
            }
        }
    }
    if (i == n)
    {
        cout << result;
    }
    else
    {
        long long int* p = new long long int[m];
        for (s = 0; s < m; s++)
        {
            p[s] = a[b[s]];
        }
        long long int w = f(p, m, m);
        for (j = i; j < n; j++)
        {
            if (p[0] < a[j])
            {
                p[0] = a[j];
                w = f(p, m, m);
                if (w - (j + 1) * d > result)
                {
                    result = w - (j + 1) * d;
                }
            }
        }
        cout << result;
    }
    return 0;
}