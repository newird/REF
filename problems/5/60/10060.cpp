#include<iostream>
using namespace std;

class MinHeap
{
private:
    long long* heap;
    long long capacity;

    void siftUp(int index)
    {
        while (index > 0 && heap[index] < heap[(index - 1) / 2]) // 当 i 不等于 0，父节点的下标为 (i - 1) / 2
        {
            long long temp = heap[index]; // do swap 
            heap[index] = heap[(index - 1) / 2];
            heap[(index - 1) / 2] = temp; // swap end
            index = (index - 1) / 2;
        }
    }

public:
    long long size;
    MinHeap(long long m)
    {
        capacity = m;
        heap = new long long[capacity];
        size = 0;
    }
    void Insert(long long value)
    {
        heap[size] = value;
        siftUp(size);
        size++;
    }
    void Remove()
    {
        if (size == 0) return;
        heap[0] = heap[--size];
        int index = 0;
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smaller = index;
            if (left < size && heap[left] < heap[smaller])
            {
                smaller = left;
            }
            if (right < size && heap[right] < heap[smaller])
            {
                smaller = right;
            }
            if (smaller != index)
            {
                long long temp = heap[index];
                heap[index] = heap[smaller];
                heap[smaller] = temp;
                index = smaller;
            }
            else
            {
                break;
            }
        }
    }
    long long top()
    {
        return heap[0];
    }
};

int main()
{
    int n, m;
    long long d;
    cin >> n >> m >> d;
    int arr[200000];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    MinHeap heap(m);
    long long sum = 0;
    long long y = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (arr[i] > 0)
        {
            if (i <= m)
            {
                heap.Insert(arr[i]);
                sum += arr[i];
            }
            else if (arr[i] > heap.top())
            {
                sum -= heap.top();
                heap.Remove();
                heap.Insert(arr[i]);
                sum += arr[i];
            }
            y = max(y, sum - d * (i + 1));
        }
    }
    cout << y << endl;
    return 0;
}