
#include <iostream>
// 使用标准命名空间
using namespace std;
// 定义主函数
int main()
{
	// 定义一个整数变量N
	long long int N;
	// 输入一个整数N
	cin >> N;
	// 如果N大于等于1，计算从1到N的总和
	if (N > 1||N==1)
	{
		// 使用等差数列求和公式
		int sum = N * (N + 1) / 2;
		// 输出结果
		cout << sum << endl;
	}
	// 如果N小于1，输出-1
	else
	{
		cout << -1 << endl;
	}
	// 返回0表示程序正常结束
	return 0;
}