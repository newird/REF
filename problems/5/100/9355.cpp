#include <iostream>

using namespace std;

class maxPriorityQueue {
public:
    long long *arr;
    long long size;
    long long capacity;

    maxPriorityQueue(long long capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new long long[capacity];
    }

    void insert(long long v) {
//        long long left = 0;
//        long long right = size - 1;
//        long long mid = (left + right) / 2;
//        while (left < right) {
//            if (arr[mid] < v) {
//                right = mid - 1;
//            } else {
//                left = mid + 1;
//            }
//            mid = (left + right) / 2;
//        }
//        for (long long i = size - 1; i >= left; i--) {
//            arr[i + 1] = arr[i];
//        }
//        arr[left] = v;
//        ++size;
        for (long long i = size - 1; i >= 0; --i) {
            if (arr[i] < v) {
                arr[i + 1] = arr[i];
            } else {
                arr[i + 1] = v;
                ++size;
                return;
            }
        }
        arr[0] = v;
        ++size;
    }

    long long back() {
        return arr[size - 1];
    }

    long long popBack() {
        return arr[--size];
    }
};


int main() {
    long long n, m, d;
    cin >> n >> m >> d;
    long long input;
    maxPriorityQueue queue(m );
    long long maxScore = 0;
    long long score = 0;
    long long cnt = 0;
    long long lastIndex = -1;
    long long i = 0;
    while (i < n && cnt < m) {
        cin >> input;
        if (input  > 0) {
            score += input  - d * (i - lastIndex);
            ++cnt;
            queue.insert(input);
            lastIndex = i;
            maxScore = max(maxScore, score);
        }
        ++i;
    }
    for (long long j = i; j < n; ++j) {
        cin >> input;
        if (input > queue.back()) {
            score += input  - queue.popBack() - d * (j - lastIndex);
            queue.insert(input);
            lastIndex = j;
            maxScore = max(maxScore, score);
        }
    }
    cout << maxScore << endl;
}