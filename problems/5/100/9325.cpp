#include <iostream>
using namespace std;
void push(long long* arr, long long& size, long long val) {
    arr[size] = val;
    long long idx = size;
    while (idx > 0) {
        long long parent = (idx - 1) / 2;
        if (arr[parent] > arr[idx]) {
            std::swap(arr[parent], arr[idx]);
            idx = parent;
        }
        else {
            break;
        }
    }
    size++;
}

void pop(long long* arr, long long& size) {
    if (size == 0) return;
    arr[0] = arr[size - 1];
    size--;

    long long idx = 0;
    while (true) {
        long long left = 2 * idx + 1;
        long long right = 2 * idx + 2;
        long long smallest = idx;
        if (left < size && arr[left] < arr[smallest]) {
            smallest = left;
        }
        if (right < size && arr[right] < arr[smallest]) {
            smallest = right;
        }
        if (smallest != idx) {
            std::swap(arr[smallest], arr[idx]);
            idx = smallest;
        }
        else {
            break;
        }
    }
}

int main() {
    long long n, m, d;
    cin >> n >> m >> d;
    long long ans = 0, sum = 0;
    long long* q = new long long[m];
    long long q_size = 0;

    for (long long i = 1; i <= n; i++) {
        long long t;
        cin >> t;
        if (t > 0) {
            if (q_size >= m) {
                sum -= q[0];
                t = max(t, q[0]);
                pop(q, q_size);
            }
            push(q, q_size, t);
            sum += t;
        }
        ans = max(ans, sum - i * d);
    }

    cout << ans << endl;
    return 0;
}
