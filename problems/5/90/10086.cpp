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
    long long* data1 = new long long[n];
    long long* position = new long long[n];
    for (long long i = 0; i < n; i++) { cin >> data1[i]; }
    position[0] = (data1[0] > 0) ? 1 : 0;
    for (long long i = 1; i < n; i++)
    {
        position[i] = position[i - 1] + ((data1[i] > 0) ? 1 : 0);
    }
    long long x = 0;
    long long lucky = max(x, data1[0] - d);
    long long num = 0;
    long long r = 0;
    long long sm = 0;
    long long sizeofh = 0;
    long long l = 1000000001;
    MinHeap* data2 = new MinHeap;
    data2->heap = new long long[m];

    for (long long i = 0; i < m - 1; i++) { data2->Insert(l); }
    if (data1[0] > 0 && m > 1) {
        data2->Remove();
        data2->Insert(data1[0]);
        sm = data1[0];
        sizeofh++;
    }

    for (long long i = 1; i < n; i++)
    {
        if (data1[i] > 0) {
            r = 0;
            r += sm;
            r = r + data1[i] - d * (i + 1);
            lucky = max(lucky, r);
        }
        if (sizeofh < m - 1 && data1[i]>0 && i != n - 1) {
            sizeofh++;
            sm += data1[i];
            data2->Insert(data1[i]);
        }
        else if (data1[i] > data2->heap[0] && m > 1 && sizeofh == m - 1 && i != n - 1)
        {
            sm = sm + data1[i] - data2->heap[0];
            data2->Remove();
            data2->Insert(data1[i]);
        }

    }
    cout << lucky;
}