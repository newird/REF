#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool down(int a, int b) {
	return a > b;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n, m, d;
	cin >> n >> m >> d;
	vector<int>arr(n);
	vector<int>num(m,0);

	int max_sum = 0;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		if (arr[i] <= num[m-1])
			continue;
		num.push_back(arr[i]);
		sort(num.begin(), num.end(), down);
		int sum = -(i+1)*d;
		for (int j = 0;j < m;j++)
			sum += num[j];
		max_sum = max(sum, max_sum);
	}

	cout << max_sum;
	return 0;
}