#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    
    vector<int> arr(n);
    vector<int> num(m, 0);
    
    priority_queue<int, vector<int>, greater<int>> pq; // 优先队列，升序排序
    
    int max_sum = 0;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        
        if (i >= m) { // 已经存满m个数
            int front = pq.top(); // 获取当前最小的数
            pq.pop();
            sum -= front; // 从sum中减去被替换的数
        }
        
        pq.push(arr[i]);
        sum += arr[i];
        
        if (i >= m - 1) { // 已经有m个数时开始计算最大和
            max_sum = max(max_sum, sum - (i + 1 - m) * d);
        }
    }
    
    cout << max_sum;
    return 0;
}