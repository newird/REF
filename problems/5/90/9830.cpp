#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
class MinHeap
{
    private:
        long long current;
        long long max;
        void siftdown(long long start, long long m);
        void siftup(long long start);
    public:
    long long *heap;
    MinHeap(long long size) 
    {
        max=size;
        heap=new long long[size];
        current=0;
    }
    /*MinHeap(int a[],int n)
    {
        max = n;
        heap=new int[n];
        for (int i = 0; i < n;i++)
            heap[i] = a[i];
        current = n;
        int currentpos = (current - 2) / 2;
        while(currentpos>=0)
        {
            siftdown(currentpos, current - 1);
            currentpos--;
        }
    }*/
    void insert(long long x)
    {
        heap[current] = x;
        siftup(current);
        current++;
    }
    void remove (long long x)
    {
        x = heap[0];
        heap[0] = heap[current - 1];
        current--;
        siftdown(0, current - 1);
    }

};
void MinHeap::siftdown(long long start,long long m)
    {
        long long i = start, j = 2 * i + 1;
        long long temp = heap[i];
        while(j<=m)
        {
            if(heap[j]>heap[j+1]&&heap[j]>heap[j+1])
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
    };
void MinHeap::siftup(long long start)
    {
        long long j = start, i = (j - 1) / 2;
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
int main()
{
    long long n, m, d;
    cin >> n >> m >> d;
    long long a[n];
    long long b = 0;
    long long day = 0;
    long long score = 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i)
            cin >> a[i];
    if(m==1)
    {
       for (int i = 0; i < n;i++)
       {
        if(score<(a[i]-(i+1)*d))
            score = a[i] - (i + 1) * d;
       }
    }
    else if(m>1)
    {
        MinHeap happiness(m);
        for (int i = 0; i < n;i++)
        {
            if (i >= 1 && m>1)
                {
                    if (a[i - 1] > 0)
                    {
                        happiness.insert(a[i - 1]);
                        day++;
                        sum += a[i - 1];
                        if (day == m)
                        {
                            sum = happiness.heap[0];
                            happiness.remove(b);
                            day--;
                        }
                    }
            }
            if((sum+(a[i] - (i + 1) * d))>score)
                    score = sum + (a[i] - (i + 1) * d);
        }
    }
    cout << score;
    return 0;
}