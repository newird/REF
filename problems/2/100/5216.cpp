#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

// 函数：计算最大利润
int maxProfit(vector<int>& prices) {
	// 边界条件：如果价格数组为空或只有一个元素，返回0
	int n = prices.size();
	if (n == 0 || n == 1) return 0;

	// 初始化动态规划数组和最低买入价
	vector<int> dp(n, 0);
	int min_price = prices[0];

	// 遍历价格数组，更新动态规划数组和最低买入价
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1], prices[i] - min_price);
		min_price = min(min_price, prices[i]);
	}

	// 返回最后一天的最大利润
	return dp[n - 1];
}

// 主函数：测试用例
int main() {
	// 输入天数和价格数组
	int n;
	cin >> n;
	vector<int> prices(n);
	for (int i = 0; i < n; i++) {
		cin >> prices[i];
	}

	// 调用函数并输出结果
	int result = maxProfit(prices);
	cout << result << endl;

	return 0;
}
