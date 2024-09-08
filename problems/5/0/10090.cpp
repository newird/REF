#include <iostream>
#include<queue>
using namespace std;



// 定义一个函数，参数为一个整数数组，一个整数n，一个整数m，一个整数d，返回值为一个整数
int maxHappiness(int arr[], int n, int m, int d) {
	// 声明一个变量ans，用于存储最大的幸福值，初始值为0
	int ans = 0;
	// 声明一个优先队列pq，用于存储每一部电影的幸福值减去下降的幸福值，从大到小排序
	priority_queue<int> pq;
	// 遍历数组，对于每一部电影，计算其幸福值减去下降的幸福值，即arr[i] - d * i，将其加入优先队列
	for (int i = 0; i < n; i++) {
		pq.push(arr[i] - d * i);
	}
	// 循环m次，每次从优先队列中取出最大的幸福值减去下降的幸福值，加上d * i，更新ans
	for (int i = 0; i < m; i++) {
		// 取出优先队列的顶部元素，即最大的幸福值减去下降的幸福值
		int top = pq.top();
		// 弹出优先队列的顶部元素
		pq.pop();
		// 更新ans，加上top + d * i
		ans += top + d * i;
	}
	// 返回ans
	return ans;
}

// 主函数
int main() {
	// 声明一个变量n，用于输入电影的数量
	int n;
	// 声明一个变量m，用于输入去电影院的次数
	int m;
	// 声明一个变量d，用于输入下降参数
	int d;
	// 从标准输入读取n,m,d的值
	cin >> n >> m >> d;
	// 声明一个动态数组arr，用于存储每一部电影的幸福值
	int* arr = new int[n];
	// 从标准输入读取arr的值
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// 调用maxHappiness函数，传入arr,n,m,d，得到返回值
	int result = maxHappiness(arr, n, m, d);
	// 将返回值输出到标准输出
	cout << result << endl;
	// 释放动态数组的内存
	delete[] arr;
	// 返回0，表示程序正常结束
	return 0;
}