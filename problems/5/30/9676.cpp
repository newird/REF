#include<iostream>
using namespace std;
class MinHeap {
private:
    int* heapArray; // 堆数组
    int maxSize; // 堆的最大容量
    int size; // 堆的当前大小

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heapArray[index] < heapArray[parent]) {
            swap(heapArray[index], heapArray[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }


    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < size && heapArray[leftChild] < heapArray[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < size && heapArray[rightChild] < heapArray[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            swap(heapArray[index], heapArray[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap(int maxSize) {
        this->maxSize = maxSize;
        heapArray = new int[maxSize];
        size = 0;
    }

    ~MinHeap() {
        delete[] heapArray;
    }

    int gettop()
    {
        return heapArray[0];
    }

    void push(int value) {
        if (size >= maxSize) {
            return; // 堆已满，无法插入
        }

        heapArray[size] = value;
        heapifyUp(size);
        size++;
    }

    void pop(int& x) {
        if (size <= 0) {
            return; // 堆为空，无法弹出元素
        }

        x = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        size--;
        heapifyDown(0);
    }

    int getSize() {
        return size;
    }
};
int main()
{
	int n = 0, m = 0, d = 0;
	cin >> n >> m >> d;
	int* a = new int[n];
	int count = 0, last = -1, happiness = 0;
    MinHeap heap(m);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
        if (a[i]- d * (i - last) >= 0 && count < m)
        {
            happiness += a[i] - d * (i - last);
            heap.push(a[i]);
            last = i;
        }
        else if (a[i] * (i - last) > 0 && count > m)
        {
            if (heap.gettop() <= a[i] - d * (i - last))
            {
                int x;
                heap.pop(x);
                happiness += a[i] - d * (i - last);
                happiness -= x;
                heap.push(a[i]);
                last = i;
            }
        }
	}
    cout << happiness;
    return 0;
}