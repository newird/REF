#include <iostream>
using namespace std;

long long int sum = 0;

struct Heap 
{
    long long int arr[200000];
    long long int size;

    Heap()
    {
        size = 0;
    }

    void push(long long int value) 
    {
        arr[size++] = value;
        int index = size - 1;
        while (index > 0)
        {
            int head = (index - 1) / 2;
            if (arr[index] < arr[head])
            { // Change the comparison to <
                int temp = arr[index];
                arr[index] = arr[head];
                arr[head] = temp;
                index = head;
            }
            else
            {
                break;
            }
        }
    }

    void pop() //ya pop biasa
    {
        if (size == 0)
        {
            return;
        }
        arr[0] = arr[--size];
        int index = 0;
        while (true) // pop sampe selesai aja pokoknya
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;
            if (left < size && arr[left] < arr[smallest])
            { 
                smallest = left;
            }
            if (right < size && arr[right] < arr[smallest]) 
            { 
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
int main() 
{
    Heap a;
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
            if (a.size < m) //masukin arr ke heapnya, jika dia masih lebih kecil daripada m nya
            {
                a.push(arr[i]);
                sum += arr[i];
            }
            else if (arr[i] > a.top())  //klo uda lebih gedhe, kita check aja sapa yg lebih gedhe antara 目前的 arr sama yang paling atas tadi
            {
                sum -= a.top(); // klo lebih gehde tukeran, yang tadi di minus yang tadi diplus
                a.pop();
                a.push(arr[i]);
                sum += arr[i];
            }
            result = max(result, sum - d * (i + 1)); // compare lagi klo sekarang tadi dengan sum yang baru apa lebih gedhe atau lebih kecil drpd hasil yang sebelumnya uda masuk
        }
    }
    cout << result << endl;

    return 0;
}