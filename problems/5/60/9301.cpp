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
        long long left = 0;
        long long right = size - 1;
        long long mid = (left + right) / 2;
        while (left < right) {
            if (arr[mid] < v) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
        // insert
        for (long long i = size - 1; i >= left; i--) {
            arr[i + 1] = arr[i];
        }
        arr[left] = v;
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
    maxPriorityQueue queue(m);
    maxPriorityQueue accumulateQueue(m);
    long long maxScore = 0;
    long long score = 0;
    long long cnt = 0;
    long long lastIndex = -1;
    long long i = 0;
    long long accumulate = 0;
    while (i < n && cnt < m) {
        cin >> input;
        if (input + accumulate - d * (i - lastIndex) > 0) {
            score += input + accumulate - d * (i - lastIndex);
            ++cnt;
            while (accumulateQueue.size != 0) {
                queue.insert(accumulateQueue.popBack());
                ++cnt;
            }
            accumulate = 0;
            queue.insert(input);
            lastIndex = i;
        } else if (input > 0) {
            if (accumulateQueue.size < m - queue.size - 1) {
                accumulateQueue.insert(input);
                accumulate += input;
            } else if (input > accumulateQueue.back()) {
                accumulate = accumulate + input - accumulateQueue.popBack();
                accumulateQueue.insert(input);
            }
        }
        ++i;
    }
    maxScore = max(maxScore, score);
    for (long long j = i; j < n; ++j) {
        cin >> input;
        if (input + accumulate - d * (i - lastIndex) > 0) {
            score += input + accumulate - queue.popBack() - d * (i - lastIndex);
            while (accumulateQueue.size != 0) {
                queue.insert(accumulateQueue.popBack());
            }
            accumulate = 0;
            queue.insert(input);
            lastIndex = i;
            maxScore = max(maxScore, score);
        } else if (input > 0) {
            if (accumulateQueue.size < m - queue.size - 1) {
                accumulateQueue.insert(input);
                accumulate += input;
            } else if (input > accumulateQueue.back()) {
                accumulate = accumulate + input - accumulateQueue.popBack();
                accumulateQueue.insert(input);
            }
        }
    }
    cout << maxScore << endl;
}