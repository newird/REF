#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool down(long long a, long long b) {
	return a > b;
}

long long max(long long a, long long b) {
	return a > b ? a : b;
}


void minHeapify(vector<long long>& arr,long long i, long long heapSize) {
	long long left = 2 * i + 1;
	long long right = left + 1;
	long long minist = i;
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
	long long  n, m, d;
	cin >> n >> m >> d;
	vector<long long>arr(n);
	vector<long long>num(m,0);

	long long max_sum = 0;
	long long sum = 0;
	for (long long i = 0;i < n;i++) {
		cin >> arr[i];
		if (arr[i] <= num[0])
			continue;
		sum += arr[i] - num[0];
		num[0] = arr[i];
		minHeapify(num, 0, m);
		max_sum = max(sum-(i+1)*d, max_sum);
	}

	cout << max_sum;
	return 0;
}