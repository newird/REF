#include <iostream>

using namespace std;

class maxPriorityQueue {
public:
    int *arr;
    int size;
    int capacity;

    maxPriorityQueue(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
    }

    void insert(int v) {
        // use binary search to find the position to insert
        int left = 0;
        int right = size - 1;
        int mid = (left + right) / 2;
        while (left < right) {
            if (arr[mid] < v) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
        // insert
        for (int i = size - 1; i >= left; i--) {
            arr[i + 1] = arr[i];
        }
        arr[left] = v;
        ++size;
    }

    int popBack() {
        return arr[--size];
    }
};


int main() {
    int n,m,d;
    cin >> n >> m >> d;
    int input;
    maxPriorityQueue queue(m);
    int maxScore = 0;
    int score = 0;
    int cnt = 0;
    int lastIndex = -1;
    int i = 0;
    int accumulate = 0;
    while (i < n && cnt < m) {
        cin >> input;
        if (input + accumulate - d * (i - lastIndex) > 0) {
            score += input + accumulate - d * (i - lastIndex);
            ++cnt;
            lastIndex = i;
            queue.insert(input);
            accumulate = 0;
        }else if(input > 0){
            accumulate += input;
        }
        ++i;
    }
    maxScore = max(maxScore, score);
    for (int j = i; j < n; ++j) {
        cin >> input;
        if (input + accumulate - d * (i - lastIndex) > 0){
            score = score + accumulate - queue.popBack() - d + input;
            lastIndex = i;
            queue.insert(input);
            maxScore = max(maxScore, score);
        } else if(input > 0){
            accumulate += input;
        }
    }
    cout << maxScore << endl;
}