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
	long long n, m, d, sum = 0, size = 0, flag = 1, t = 0;
	cin >> n >> m >> d;
	long long a[200000]; long long b[1000];
	for (long long i = 0; i < n; i++) { cin >> a[i]; }
	if (m == 0) { cout << 0; }
	else {
		for (long long i = 0; i < n; i++) {
			if (size == m - 1 && flag == 1) { for (long long j = m - 1; j >= 0; j--) { Adjust(a, j, m); }flag = 0; }
			if (size < m - 1 && i >= 1 && a[i - 1] > 0) {
				b[size] = a[i - 1]; size++; t += a[i - 1];
			}
			else if (size == m - 1 && i >= 1 && a[i - 1] > b[0]) {
				t -= b[0]; t += a[i - 1]; b[0] = a[i - 1]; Adjust(a, 0, m);
			}
			sum = (sum > t + a[i] - d * (i + 1)) ? sum : (t + a[i] - d * (i + 1));
		}
		cout << sum;
	}
	return 0;
}