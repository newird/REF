#include <iostream>
using namespace std;
class TreeNode
{
    long long* root;
    long long size;
    long long maxsize;
public:
    TreeNode(long long sz) 
    {
        maxsize = sz;
        root = new long long[sz];
        size = 0;
    }

    void siftdown(long long start, long long m) 
    {
        long long i = start;
        long long j = 2 * i + 1;
        long long temp = root[i];
        while (j <= m) 
        {
            if (j <= m && root[j] > root[j + 1])
                j++;
            if (temp <= root[j])
                break;
            else 
            {
                root[i] = root[j]; i = j;
                j = 2 * i + 1;
            }
        }
        root[i] = temp;
    }
    void siftup(long long start) 
    {
        long long j = start, i = (j - 1) / 2;
        long long temp = root[j];
        while (j > 0) 
        {
            if (root[i] <= temp)
                break;
            else 
            {
                root[j] = root[i];
                j = i;
                i = (i - 1) / 2;
            }
        }
        root[j] = temp;
    }

    void Insert(long long c) 
    {
        root[size] = c;
        siftup(size);
        size++;
    }
    void Delete() 
    {
        root[0] = root[size - 1];
        size--;
        siftdown(0, this->size - 1);
    }
    long long top() 
    {
        return root[0];
    }
};
int main()
{
    long long n, m, d;
    cin >> n >> m >> d;
    long long* data = new long long[n];
    for (long long i = 0; i < n; i++)
        cin >> data[i];
    if (m == 0) 
    {
        cout << "0"<<endl;
        return 0;
    }
    TreeNode root(m);
    long long res = 0;
    long long sum = 0;
    long long las = 0;
    long long sz = 0;
    while (las < n) //看作中间天数正常加，只是最后一天有衰减
    {
        long long temp = (long long)data[las] - d * (las + 1);//与第0天相比
        if (m > 1 && las >= 1) 
        {
            if (data[las - 1] > 0) 
            {
                root.Insert(data[las - 1]);//维护最小堆
                sz++;
                sum += data[las - 1];
                if (sz == m) 
                {
                    sum -= root.top();
                    root.Delete();
                    sz--;
                }
            }
        }
        if (sum + temp > res)
            res = sum + temp;
        las++;
    }
    cout << res<<endl;
    return 0;
}
