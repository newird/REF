#include<iostream>
using namespace std;

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
    int n, m;
    long long d;
    cin >> n >> m >> d;
    MinHeap heap(m);
    long long sum = 0;
    long long max = 0;
    for (int i = 1; i <= n; ++i)
    {
        long long x;
        cin >> x;

        if (x > 0)
        {
            if (i <= m) //堆还没满
            {
                heap.Insert(x);
                sum += x;
                long long happy = sum - i * d;
                if (happy > max)
                    max = happy;
            }

            else  //堆满了
            {
                long long top = heap.top(); 
                long long prev_happy = sum - (i - 1) * d; 
                sum = sum + x - top; 
                long long happy = sum - i * d; 

                if (happy > prev_happy) //比较新旧幸福值
                {
                    heap.Remove(top);
                    heap.Insert(x);
                    if (happy > max)
                        max = happy;
                }
                else
                {
                    sum = sum - x + top;
                }
            }
        }
    }

    cout << max;
    return 0;
}