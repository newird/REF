#include<iostream>
#include<vector>
using namespace std;

int max_num=0;

void happy(const vector<int>& arr,int num,int d,int index,int sum) {
	if (num <= 0)return;
	for (int i = index+1;i < arr.size();i++) {
		if (arr[i] <= 0)continue;
		int sum_ = sum;
		sum_ += arr[i] - d * (i - index);
		max_num = max_num > sum_ ? max_num : sum_;
		happy(arr, num - 1, d, i, sum_);
	}
}

int main() {
	int n, m, d;
	cin >> n >> m >> d;

	vector<int>arr(n);
	for (int i = 0;i < n;i++)
		cin >> arr[i];
	happy(arr, m, d, -1, 0);
	cout << (max_num > 0 ? max_num : 0);
	return 0;
}