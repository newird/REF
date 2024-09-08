#include <iostream>
using namespace std;
#define N 1000000

struct Heap {
    long long int arr[N];
    long long int size;

    Heap() : size(0) {}

    void push(long long int value) {
        arr[size++] = value;
        int index = size - 1;
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[index] < arr[parent]) { 
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void pop() {
        if (size == 0) {
            return;
        }
        arr[0] = arr[--size];
        int idx = 0;
        while (true) {
            int smallest = idx;
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;

            if (left < size && arr[left] < arr[smallest]) {   
                smallest = left;
            }
            if (right < size && arr[right] < arr[smallest]) { 
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
        if (size > 0)return arr[0];
        else return 0;
    }
};

long long int Solution(Heap a,long long int arr[], long long int add, long long int res, long long int n, long long int m, long long int d)
{
    for (long long int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            if (a.size < m) {    //代表是栈空
                a.push(arr[i]);
                add += arr[i];
            }
            else if (arr[i] > a.top()) {   //如果加了之后结果更大
                add -= a.top();
                a.pop();
                a.push(arr[i]);
                add += arr[i];
            }
            res = max(res, add - d * (i + 1));
        }
    }
    return res;
}

int main() {
    Heap a;
    long long int n, m, d, arr[N];
    cin >> n >> m >> d;
    for (long long int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long int add = 0;   //用来存加了之后当前的结果
    long long int res = 0;   //用来存最终的最优结果
    
    res = Solution(a,arr, add, res, n, m,d);
    cout << res;

    return 0;
}