#include <iostream>
#include<queue>
using namespace std;

// 定义一个函数，参数为一个整数数组，一个整数m，一个整数d，返回值为一个整数
int maxHappiness(int arr[], int m, int d) {
	// 声明一个变量n，用于存储数组的长度
	int n = sizeof(arr) / sizeof(arr[0]);
	// 声明一个变量ans，用于存储最大的幸福值，初始值为0
	int ans = 0;
	// 声明一个变量last，用于存储上一次去电影院的天数，初始值为0
	int last = 0;
	// 声明一个优先队列pq，用于存储每一部电影的幸福值，从大到小排序
	priority_queue<int> pq;
	// 遍历数组，对于每一部电影，将其幸福值加入优先队列
	for (int i = 0; i < n; i++) {
		pq.push(arr[i]);
	}
	// 循环m次，每次从优先队列中取出最大的幸福值，计算gap，更新ans和last
	for (int i = 0; i < m; i++) {
		// 取出优先队列的顶部元素，即最大的幸福值
		int top = pq.top();
		// 弹出优先队列的顶部元素
		pq.pop();
		// 计算距离上一次去电影院的天数，即gap
		int gap = i + 1 - last;
		// 更新ans，减去下降的幸福值
		ans += top - d * gap;
		// 更新last，记录当前去电影院的天数
		last = i + 1;
	}
	// 返回ans
	return ans;
}

// 主函数
int main() {
	// 声明一个变量n，用于输入数组的长度
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
	// 调用maxHappiness函数，传入arr,m,d，得到返回值
	int result = maxHappiness(arr, m, d);
	// 将返回值输出到标准输出
	cout << result << endl;
	// 释放动态数组的内存
	delete[] arr;
	// 返回0，表示程序正常结束
	return 0;
}
