#include <iostream>
using namespace std;
#define N 200000

long long int sum = 0;
long long int y = 0;

struct CustomHeap 
{
    long long int arr[N];
    long long int size;

    CustomHeap() : size(0) {}

    void push(long long int value) {
        arr[size++] = value;
        int idx = size - 1;
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (arr[idx] < arr[parent]) { // Change the comparison to <
                swap(arr[idx], arr[parent]);
                idx = parent;
            }
            else {
                break;
            }
        }
    }

    void pop() {
        if (size == 0) return;
        arr[0] = arr[--size];
        int idx = 0;
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int smallest = idx;
            if (left < size && arr[left] < arr[smallest]) { // Change the comparison to <
                smallest = left;
            }
            if (right < size && arr[right] < arr[smallest]) { // Change the comparison to <
                smallest = right;
            }
            if (smallest != idx) {
                swap(arr[idx], arr[smallest]);
                idx = smallest;
            }
            else {
                break;
            }
        }
    }

    long long int top() {
        return size > 0 ? arr[0] : 0;
    }
};
int main() {
    CustomHeap a;
    long long int n, m, d;
    long long arr[200000];
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
            int temp = sum - d * (i + 1);
            if (y < temp)
            {
                y = temp;
            }
        }
    }
    cout << y << endl;

    return 0;
}