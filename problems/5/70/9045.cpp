#include <iostream>
using namespace std;

int *mHeap = new int[200000];
int count = 0;

int peek()
{
    return mHeap[0];
}

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

int parent(int i)
{
    return (i - 1) / 2;
}

void siftup(int i)
{
    int flag = 0;
    while(i > 0)
    {
        int p = parent(i);
        if(mHeap[i] >= mHeap[p]) 
            break;
        swap(mHeap[i], mHeap[p]);
        i = p; 
    }
}

void siftdown(int i)
{
    while(i < count)
    {
        int l = left(i), r = right(i), ma = i;
        if(l < count && mHeap[l] < mHeap[ma])
            ma = l;
        if(r < count && mHeap[r] < mHeap[ma])
            ma = r;
        if(ma == i)
            break;
        swap(mHeap[i], mHeap[ma]);
        i = ma;
    }
}

void push(int val)
{
    mHeap[count] = val;
    siftup(count);
    count++;
}

void pop()
{
    swap(mHeap[0], mHeap[count - 1]);
    count--;
    siftdown(0);
}

int main()
{
    int n, m, d, a;
    cin >> n >> m >> d;
    int sum = 0;
    int total_gap = 0;
    int res = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a;
        total_gap = d * i;
        if(a >= 0 && count < m)
        {
            push(a);
            sum += a;
            res = max(res, sum - total_gap);
        }
        else if(count == m && a > peek())
        {
            sum -= peek();
            pop();
            push(a);
            sum += a;
            res = max(res, sum - total_gap);
        }
    }
    cout << res << endl;
    return 0;
}