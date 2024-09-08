#include <iostream>
using namespace std;
class happiness
{
    long long current;
    long long *Heap;
public:
    happiness(int size)
    {
        current = 0;
        Heap=new int[size];
    }
    void Heapify(int start, int end, bool is_siftdown) 
    {
        int i = start;
        int j = is_siftdown ? 2 * i + 1 : (i - 1) / 2;
        int temp = Heap[i];
        if ((is_siftdown && j <= end) || (!is_siftdown && i > 0)) 
        {
            if (is_siftdown && j < end && Heap[j] > Heap[j+1]) 
            {
                j++;
            }
            if ((is_siftdown && temp <= Heap[j]) || (!is_siftdown && temp >= Heap[j])) 
            {
                return;
            } 
            else 
            {
                Heap[i] = Heap[j];
                i = j;
                j = is_siftdown ? 2 * i + 1 : (i - 1) / 2;
            }
        }
        Heap[i] = temp;
    }
    void modifyHeap(int x, bool is_insert) 
    {
        if (is_insert) 
        {
            Heap[current] = x;
            Heapify(current,0,false);
            current++;
        }   
        else 
        {
            Heap[0] = Heap[current - 1];
            current--;
            Heapify(0, this->current - 1,true);
        }
    }
    int gettop()
    {
        return Heap[0];
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
        happiness h;
        h.minheap(m);
        int score = 0;
        int sum = 0;
        int size = 0;
        int last = 0;
        while (last<n)
        {
            int temp = (int)a[last] - d * (last + 1);
            if(m>1&&last>=1)
            {
                if(a[last-1]>0)
                {
                    h.modifyHeap(a[last - 1],true);
                    size++;
                    sum += a[last - 1];
                    if(size==m)
                    {
                        sum = h.gettop();
                        h.modifyHeap(0,false);
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
