#include <iostream>
using namespace std;

class Heap {//minheap
private:
    int* data;//数组开头
    int count;//大小
public:
    Heap(int capacity) {//创建对应大小的数组(堆)
        data = new int[capacity + 1];
        count = 0;
    }
    ~Heap() {//删除堆
        delete[] data;
    }
    int size() {//返回大小
        return count;
    }
    bool isEmpty() {//判断是否为空
        return count == 0;
    }
    void insert(int item) {//加入元素
        data[++count] = item;//先放入最后一位
        percolate_up(count);
    }
    void percolate_up(int k) {//保持最小堆(从最后开始)
        while (k > 1 && data[k / 2] >= data[k]) {
            swap(data[k / 2], data[k]);
            k /= 2;
        }
    }
    int extract() {//提取元素
        int ret = data[1];
        swap(data[1], data[count]);
        count--;
        percolate_down(1);
        return ret;
    }
    void percolate_down(int k) {//保持最小堆(从最前开始)
        while (2 * k <= count) {
            int j = 2 * k;
            if (j + 1 <= count && data[j + 1] < data[j]) {
                j = j + 1;
            }
            if (data[k] <= data[j])
                break;
            swap(data[k], data[j]);
            k = j;
        }
    }
    int top() {//返回最小值
        return data[1];
    }
};

int arr[200010];
int main() {
    int n, m, d;
    cin >> n >> m >> d;

    Heap heap(200010);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long maxSum = 0;
    long long preSum = 0;//除了最后一天以外,最多m-1天在之前的幸福值的和
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {//小于0的不要
            long long tmp = (long long)arr[i] + preSum - (long long)d * (long long)(i + 1);
            maxSum = max(maxSum, tmp);
            if (heap.size() < m - 1) {//最后一天没到m天时
                heap.insert(arr[i]);
                preSum += arr[i];//先加上
            }
            else {//大于0的天数多于m天时
                if (arr[i] > heap.top()) {
                    preSum = preSum + arr[i] - heap.top();//只要最大的m-1天
                    heap.extract();//弹出堆顶
                    heap.insert(arr[i]);
                }
            }
        }
    }

    cout << maxSum;
}
