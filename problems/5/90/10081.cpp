#include <iostream>
using namespace std;

class MinHeap {
public:
    MinHeap() {}
    bool Insert(long long& x)
    {
        heap[currentSize] = x;
        siftUp(currentSize);
        currentSize++;
        return true;
    };
    void siftUp(long long start)
    {
        long long j = start, i = (j - 1) / 2;
        long long temp = heap[j];
        while (j > 0)
        {
            if (heap[i] <= temp) break;
            else { heap[j] = heap[i];  j = i;  i = (i - 1) / 2; }

        }
        heap[j] = temp;
    };
    bool Remove()
    {
        long long x = heap[0];
        heap[0] = heap[currentSize - 1];
        currentSize--;
        siftDown(0, currentSize - 1);
        return true;
    };
    long long* heap;
    long long currentSize = 0;
    void siftDown(long long start, long long m)
    {
        long long i = start, j = 2 * i + 1;
        long long temp = heap[i];
        while (j <= m)
        {
            if (j < m && heap[j] > heap[j + 1])
                j++;
            if (temp <= heap[j])
                break;
            else
            {
                heap[i] = heap[j];  i = j; j = 2 * j + 1;
            }

        }
        heap[i] = temp;
    };

};

int main()
{
    long long n, m, d;
    cin >> n >> m >> d;
    long long* a = new long long[n];
    long long* pos = new long long[n];//截至a【i】有几个正数
    for (long long i = 0; i < n; i++) { cin >> a[i]; }
    pos[0] = (a[0] > 0) ? 1 : 0;
    for (long long i = 1; i < n; i++)
    {
        pos[i] = pos[i - 1] + ((a[i] > 0) ? 1 : 0);
    }
    long long x = 0;
    long long maxLuck = max(x, a[0] - d);
    long long num = 0;
    long long record = 0;
    long long sum_minheap = 0;
    long long heapsize = 0;
    long long large = 1000000001;
    MinHeap* b = new MinHeap;
    b->heap = new long long[m];

    for (long long i = 0; i < m - 1; i++) { b->Insert(large); }
    if (a[0] > 0 && m > 1) {
        b->Remove();
        b->Insert(a[0]);
        sum_minheap = a[0];
        heapsize++;
    }

    for (long long i = 1; i < n; i++)
    {
        if (a[i] > 0) {
            record = 0;
            record += sum_minheap;
            record = record + a[i] - d * (i + 1);
            maxLuck = max(maxLuck, record);
        }
        if (heapsize < m - 1 && a[i]>0 && i != n - 1) {
            heapsize++;
            sum_minheap += a[i];
            b->Insert(a[i]);
        }
        else if (a[i] > b->heap[0] && m > 1 && heapsize == m - 1 && i != n - 1)
        {
            sum_minheap = sum_minheap + a[i] - b->heap[0];
            b->Remove();
            b->Insert(a[i]);
        }

    }
    cout << maxLuck;
}