#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
class MinHeap
{
    private:
        int current;
        int max;
        void siftdown(int start, int m);
        void siftup(int start);
    public:
    int *heap;
    MinHeap(int size) 
    {
        max=size;
        heap=new int[size];
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
    void insert(int x)
    {
        heap[current] = x;
        siftup(current);
        current++;
    }
    void remove (int x)
    {
        x = heap[0];
        heap[0] = heap[current - 1];
        current--;
        siftdown(0, current - 1);
    }

};
void MinHeap::siftdown(int start,int m)
    {
        int i = start, j = 2 * i + 1;
        int temp = heap[i];
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
void MinHeap::siftup(int start)
    {
        int j = start, i = (j - 1) / 2;
        int temp = heap[j];
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
    int n, m, d;
    cin >> n >> m >> d;
    int a[n];
    int b = 0;
    int day = 0;
    int score = 0;
    int sum = 0;
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