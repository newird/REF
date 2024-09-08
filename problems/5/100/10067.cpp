#include <iostream>
using namespace std;

const int MAX_SIZE = 200000;

long long int heapArr[MAX_SIZE];
int heapSize = 0;

void push(long long int value) 
{
    heapArr[heapSize++] = value;
    int index = heapSize - 1;
    while (index > 0) 
    {
        int parent = (index - 1) / 2;
        if (heapArr[index] < heapArr[parent]) 
        {
            int temp = heapArr[index];
            heapArr[index] = heapArr[parent];
            heapArr[parent] = temp;
            index = parent;
        }
        else 
        {
            break;
        }
    }
}

void pop() 
{
    if (heapSize == 0) 
    {
        return;
    }
    heapArr[0] = heapArr[--heapSize];
    int index = 0;
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smaller = index;
        if (leftChild < heapSize && heapArr[leftChild] < heapArr[smaller]) 
        {
            smaller = leftChild;
        }
        if (rightChild < heapSize && heapArr[rightChild] < heapArr[smaller]) 
        {
            smaller = rightChild;
        }
        if (smaller != index) 
        {
            int temp = heapArr[index];
            heapArr[index] = heapArr[smaller];
            heapArr[smaller] = temp;
            index = smaller;
        }
        else 
        {
            break;
        }
    }
}

long long int top() 
{
    if (heapSize > 0) 
    {
        return heapArr[0];
    }
    else 
    {
        return 0;
    }
}

int main()
{
    long long int n, m, d;
    long long arr[MAX_SIZE];
    long long result = 0;
    long long int sum = 0;
    cin >> n >> m >> d;
    for (long long int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    for (long long int i = 0; i < n; i++) 
    {
        if (arr[i] > 0) 
        {
            if (heapSize < m) 
            {
                push(arr[i]);
                sum += arr[i];
            }
            else if (arr[i] > top()) 
            {
                sum -= top();
                pop();
                push(arr[i]);
                sum += arr[i];
            }
            result = max(result, sum - d * (i + 1));
        }
    }
    cout << result << endl;
    return 0;
}
    