#include<iostream>
using namespace std;
void shiftdown(int i, int k, int* a)
{
    int flag = 0, temp;
    int t = i;
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
int f(int* a, int n, int k)
{
    int c = 0, q = k, j, i,count=0,max=0;
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
        if(a[i]>0)
        count += a[i];
    }
    return count;
}
int main()
{
	int n, m, d,i;
	cin >> n >> m >> d;
    int* a = new int[n];
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
    int max = a[0]-d, t;
    for (i = 1; i < m; i++)
    {
        t = 0;
        for (int j = 0; j < i; j++)
            if (a[j] > 0)
                t += a[j];
        t += a[i];
        t-= (i+1) * d;
        if (t > max)
            max = t;
    }
    for (i = m; i < n; i++)
    {
        t = f(a, i , m - 1) + a[i] - (i+1) * d;
        if (t > max)
            max = t;
    }
    if (max < 0)
        max = 0;
    cout << max;
    return 0;
}