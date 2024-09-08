#include <iostream>
using namespace std;
class happiness
{
    long long *heap;
    long long current;
    long long min;
    public:
    happiness(long long size)
    {
        min = size;
        heap=new long long[size];
        current = 0;
    }
   

    void siftdown(long long start,long long m)
    {
        long long i = start;
        long long j = 2 * i + 1;
        long long temp = heap[i];
        while(j<=m)
        {
            if(heap[j]>heap[j+1])
                j++;
            if(temp<=heap[j])
                break;
            else
            {
                heap[i] = heap[j];
                i = j;
                j = 2 * i + 1;
            }
        }
        heap[i] = temp;
    }
    void siftup(long long start)
    {
        long long j = start;
        long long i = (j - 1) / 2;
        long long temp = heap[j];
        while(j>0)
        {
            if(heap[i]<=temp)
                break;
            else
            {
                heap[j] = heap[i];
                j = i;
                i = (i - 1) / 2;
            }
        }
        heap[j] = temp;
    }
    void insert(long long x)
    {
        heap[current] = x;
        siftup(current);
        current++;
    }
    void erase ()
    {
        heap[0] = heap[current - 1];
        current--;
        siftdown(0, this->current - 1);
    }
    long long gettop()
    {
        return heap[0];
    }
};
int main()
{
    int n, m, d;
    cin >> n >> m >> d;
    int a[n];
    for (int i = 0; i < n;++i)
        cin >> a[i];
    if(m==0)
        cout << "0";
    else
    {
        happiness h(m);
        long long score = 0;
        long long sum = 0;
        long long size = 0;
        long long last = 0;
        while (last<n)
        {
            long long temp = (long long)a[last] - d * (last + 1);
            if(m>1&&last>=1)
            {
                if(a[last-1]>0)
                {
                    h.insert(a[last - 1]);
                    size++;
                    sum += a[last - 1];
                    if(size==m)
                    {
                        sum = h.gettop();
                        h.erase();
                        size--;
                    }
                }
            }
            if((sum+temp)>score)
                score = sum + temp;
            last++;
        }
        cout << score;
    }
    return 0;
}