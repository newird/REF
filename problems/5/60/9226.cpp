#include <iostream>
using namespace std;

void Adjust(long long a[],long long k, long long n) {
	while (2 * k + 2 <= n) {
		long long i;
		if (2 * k + 2 < n) {
			i = (a[2 * k + 1] > a[2 * k + 2]) ? (2 * k + 2) : (2 * k + 1);
			if (a[k] > a[i]) {
				long long tmp = a[k]; a[k] = a[i]; a[i] = tmp;
			}
			k = i;
		}
		else if ((2 * k + 2 == n) && (a[k] > a[n - 1])) {
			i = n - 1;
			long long tmp = a[k]; a[k] = a[i]; a[i] = tmp;
			k = i;
		}
		else { break; }
	}
}

int main() {
	long long n, m, d, sum = 0, size = 0, flag = 1;
	cin >> n >> m >> d;
	long long a[1000]; long long b[1000];
	for (long long i = 0; i < n; i++) { cin >> a[i]; }
	for (long long i = 0; i < n; i++) {
		if (size == m && flag == 1) { for (long long j = m - 1; j >= 0; j++) { Adjust(a, j, m); }flag = 0; }
		if (size < m - 1 && i >= 1 && a[i - 1]>0) {
			b[size] = a[i - 1]; size++;
		}
		else if (size == m && a[i - 1] > b[0]) {
			b[0] = a[i - 1]; Adjust(a, 0, m);
		}
		long long t = a[i] - d * i - d;
		for (long long j = 0; j < size; j++) { t += b[j]; }
		sum = (sum > t) ? sum : t;
	}
	cout << sum;
	return 0;
}