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


void minHeapify(vector<int>& arr,int i, int heapSize) {
	int left = 2 * i + 1;
	int right = left + 1;
	int minist = i;
	if (left<heapSize&&arr[left] < arr[minist])
		minist = left;
	if (right<heapSize&&arr[right] < arr[minist])
		minist = right;
	if (i != minist) {
		swap(arr[i], arr[minist]);
		minHeapify(arr, minist, heapSize);
	}
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
		sum += arr[i] - num[0];
		num[0] = arr[i];
		minHeapify(num, 0, m);
		max_sum = max(sum-(i+1)*d, max_sum);
	}

	cout << max_sum;
	return 0;
}