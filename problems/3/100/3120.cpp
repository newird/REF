#include <iostream>
#include <vector>
using namespace std;

// 定义一个函数，将两个大整数相加，返回一个存储结果的向量
vector<int> add(vector<int> a, vector<int> b) {
	vector<int> c; // 存储结果的向量
	int carry = 0; // 存储进位的变量
	int i = 0; // 遍历两个向量的下标
	while (i < a.size() || i < b.size() || carry) { // 当两个向量都没有遍历完或者有进位时
		int sum = carry; // 计算当前位的和，初始为进位
		if (i < a.size()) sum += a[i]; // 如果a还有未遍历的位，加上a的当前位
		if (i < b.size()) sum += b[i]; // 如果b还有未遍历的位，加上b的当前位
		c.push_back(sum % 10); // 将和的个位存入结果向量
		carry = sum / 10; // 更新进位为和的十位
		i++; // 更新下标
	}
	return c; // 返回结果向量
}

int main() {
	int n, m; // 输入两个整数的位数
	cin >> n >> m;
	vector<int> a(n), b(m); // 定义两个存储大整数的向量
	for (int i = 0; i < n; i++) cin >> a[i]; // 输入a的每一位数字
	for (int i = 0; i < m; i++) cin >> b[i]; // 输入b的每一位数字
	vector<int> c = add(a, b); // 调用函数，计算a + b，得到结果向量c
	for (int i = c.size() - 1; i >= 0; i--) cout << c[i]; // 输出c的每一位数字，从高位到低位
	cout << endl;
	return 0;
}