#include<iostream>
using namespace std;

long long sum = 0;
long long y = 0;

class MinHeap
{
private:
    long long* heap;
    long long size;
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
    void siftDown(int index)
    {
        while (2 * index + 1 <= size - 1)
        {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallerChild = leftChild;
            if (rightChild < size && heap[rightChild] < heap[smallerChild])
            {
                smallerChild = rightChild;
            }
            if (heap[index] <= heap[smallerChild])
            {
                break;
            }
            else
            {
                long long temp = heap[index]; // do swap
                heap[index] = heap[smallerChild];
                heap[smallerChild] = temp; // swap end, the smallerChild now becomes the root
                index = smallerChild;
            }
        }
    }

public:
    MinHeap(long long k)
    {
        capacity = k;
        heap = new long long[capacity];
        size = 0;
    }
    void Insert(long long value)
    {
        heap[size] = value;
        siftUp(size);
        size++;
    }
    void Remove(long long value)
    {
        heap[0] = value;
        siftDown(0);
    }
    long long top()
    {
        return heap[0];
    }
};

int main()
{
    long long n, m, d;
    cin >> n >> m >> d;
    long long arr[200000];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    MinHeap heap(m);
    for (int i = 1; i <= n; ++i)
    {
        if (i <= m)
        {
            if (arr[i] > 0)
            {
                heap.Insert(arr[i]);
                sum += arr[i];
            }
        }
        else
        {
            int top = heap.top();
            if (arr[i] > top)
            {
                sum -= top;
                heap.Remove(arr[i]);
                sum += arr[i];
            } 
        }
        y = max(y, sum - d * (i + 1));
    }
    cout << y << endl;
    return 0;
}
