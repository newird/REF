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
	int sum = 0;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		if (arr[i] <= num[m-1])
			continue;
		for(int j=0;j<m;j++)
			if (arr[i] > num[j]) {
				sum += arr[i] - num[m-1];
				num.insert(num.begin() + j, arr[i]);
				break;
			}
		max_sum = max(sum-(i+1)*d, max_sum);
	}

	cout << max_sum;
	return 0;
}