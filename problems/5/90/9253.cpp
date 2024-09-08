#include <iostream>
#include <cstring>
int powerof2[31] = {
	0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0x8000,
	0x10000, 0x20000, 0x40000, 0x80000, 0x100000, 0x200000, 0x400000, 0x800000,
	0x1000000, 0x2000000, 0x4000000, 0x8000000, 0x10000000, 0x20000000, 0x40000000
};
inline long long* get_point(long long* arr, int level, int number, int n) {		//层数从1开始,number从0开始
	return arr + powerof2[level - 1] - 1 + number;
}
inline long long* get_point_left(long long* arr, int level, int number, int n) {
	if (powerof2[level] - 1 + number * 2 >= n) {
		return nullptr;
	}
	return arr + powerof2[level] - 1 + number * 2;
}
inline long long* get_point_right(long long* arr, int level, int number, int n) {
	if (powerof2[level] + number * 2 >= n) {
		return nullptr;
	}
	return arr + powerof2[level] + number * 2;
}

void heapify(long long* arr, int k, int i, int n) {		//k层数 i该层第几个 n总节点数
//层数从1开始,每层从0开始
	long long* p = get_point(arr, k, i, n), *p1 = get_point_left(arr, k, i, n), *p2 = get_point_right(arr, k, i, n);
	if (p1 && p2 ) {
		if (*p1 < *p2) {
			if (*p1 < *p) {
				int temp = *p;
				*p = *p1;
				*p1 = temp;
				heapify(arr, k + 1, i * 2, n);
			}
		} else {
			if (*p2 < *p) {
				int temp = *p;
				*p = *p2;
				*p2 = temp;
				heapify(arr, k + 1, i * 2 + 1, n);
			}
		}
	} else if (p1) {
		if (*p1 < *p) {
			int temp = *p;
			*p = *p1;
			*p1 = temp;
			heapify(arr, k + 1, i / 2, n);
		}
	}
}

void heapify_up(long long* arr, int k, int i, int n) {
	bool changed{};
	long long* p = get_point(arr, k, i, n), *p1 = get_point_left(arr, k, i, n), *p2 = get_point_right(arr, k, i, n);
	if (p1 && p2 ) {
		if (*p1 < *p2) {
			if (*p1 < *p) {
				int temp = *p;
				*p = *p1;
				*p1 = temp;
				changed = 1;
			}
		} else {
			if (*p2 < *p) {
				int temp = *p;
				*p = *p2;
				*p2 = temp;
				changed = 1;
			}
		}
	} else if (p1) {
		if (*p1 < *p) {
			int temp = *p;
			*p = *p1;
			*p1 = temp;
			changed = 1;
		}
	}
	if (changed&&k>1) {
		heapify_up(arr,k-1,i/2,n);
	}
}

using namespace std;
class priority_queue {
	public:
		long long size;
		long long capacity;
		long long* data;
		priority_queue() {
			data = new long long [4];
			capacity = 4;
			size = 0;
		}
		void pop() {
			swap(data[0], data[size - 1]);
			size--;
			heapify(data, 1, 0, size);
		}
		long long top() {
			return data[size - 1];
		}
		void push(long long v) {
			if (size == capacity) {
				capacity *= 2;
				long long* temp = new long long [capacity];
				memcpy(temp, data, size * sizeof(long long));
				delete[] data;
				data = temp;
			}
			data[size++] = v;
			if (size > 1) {
				int i = 1;
				for (;; i++) {
					if (size <= powerof2[i] - 1) {
						break;
					}
				}
				heapify_up(data, i - 1, (size - powerof2[i - 1] - 1) / 2, size);
			}
		}
};

int main() {
	long long happiness = 0;
	int n, m;
	long long d;
	cin >> n >> m >> d;
	long long a[n + 2];
	long long dp[n + 2] {};
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a[i] = temp;
	}
	priority_queue q;
	long long sum{};
	for (int i = 0; i < n; i++) {
		if (q.size < m) {
			if (a[i] > 0) {
				q.push(a[i]);
				sum += a[i];
			}
		} else {
			if (a[i] > q.top()) {
				long long temp = q.top();
				q.pop();
				q.push(a[i]);
				sum -= temp;
				sum += a[i];
			}
		}
		dp[i] = sum;
	}
	for (int i = 0; i < n; i++) {
		if (dp[i] - d * (i + 1) > happiness) {			//一定是选择前面的较大的m（或少于m）个数
			happiness = dp[i] - d * (i + 1);
		}
	}
	cout << happiness;

	return 0;
}