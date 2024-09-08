#include <iostream>
using namespace std;

long long int sum = 0;
long long int arr[200000];
long long int size = 0;

void push(long long int value) {
    arr[size++] = value;
    int index = size - 1;
    while (index > 0) {
        int head = (index - 1) / 2;
        if (arr[index] < arr[head]) {
            int temp = arr[index];
            arr[index] = arr[head];
            arr[head] = temp;
            index = head;
        } else {
            break;
        }
    }
}

void pop() {
    if (size == 0) {
        return;
    }
    arr[0] = arr[--size];
    int index = 0;
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        if (left < size && arr[left] < arr[smallest]) {
            smallest = left;
        }
        if (right < size && arr[right] < arr[smallest]) {
            smallest = right;
        }
        if (smallest != index) {
            int temp = arr[index];
            arr[index] = arr[smallest];
            arr[smallest] = temp;
            index = smallest;
        } else {
            break;
        }
    }
}

long long int top() {
    if (size > 0) {
        return arr[0];
    } else {
        return 0;
    }
}

int main() {
    long long int n, m, d;
    long long result = 0;
    cin >> n >> m >> d;
    for (long long int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (long long int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            if (size < m) {
                push(arr[i]);
                sum += arr[i];
            } else if (arr[i] > top()) {
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
