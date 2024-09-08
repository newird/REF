#include <iostream>
using namespace std;
#define N 200000

long long int sum = 0;

struct CustomHeap 
{
    long long int arr[N];
    long long int size;

    CustomHeap()
    {
        size = 0;
    }

    void push(long long int value) 
    {
        arr[size++] = value;
        int index = size - 1;
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (arr[index] < arr[parent])
            { // Change the comparison to <
                int temp = arr[index];
                arr[index] = arr[parent];
                arr[parent] = temp;
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
        if (size == 0)
        {
            return;
        }
        arr[0] = arr[--size];
        int index = 0;
        while (true) 
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;
            if (left < size && arr[left] < arr[smallest])
            { // Change the comparison to <
                smallest = left;
            }
            if (right < size && arr[right] < arr[smallest]) 
            { // Change the comparison to <
                smallest = right;
            }
            if (smallest != index)
            {
                int temp = arr[index];
                arr[index] = arr[smallest];
                arr[smallest] = temp;
                index = smallest;
            }
            else
            {
                break;
            }
        }
    }

    long long int top() 
    {

        if (size > 0)
        {
            return arr[0];
        }
        else
        {
            return 0;
        }

    }
};
int main() {
    CustomHeap a;
    long long int n, m, d;
    long long arr[200000];
    long long result = 0;
    cin >> n >> m >> d;
    for (long long int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    for (long long int i = 0; i < n; i++)
    {
        if (arr[i] > 0) 
        {
            if (a.size < m) 
            {
                a.push(arr[i]);
                sum += arr[i];
            }
            else if (arr[i] > a.top()) 
            {
                sum -= a.top();
                a.pop();
                a.push(arr[i]);
                sum += arr[i];
            }
            result = max(result, sum - d * (i + 1));
        }
    }
    cout << result << endl;

    return 0;
}