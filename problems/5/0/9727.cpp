#include <iostream>
using namespace std;

long long WatchMovie(int *a, int pre, int now, int n, int d, int times, int m) {
	long long sum = 0;
	if (now + 1 > n || times == m)
		sum = 0;
	else if (a[now] < 0)
		sum = WatchMovie(a, pre, now + 1, n, d, times, m);
	else
		sum = -d * (now - pre) + a[now] + WatchMovie(a, now, now + 1, n, d, times + 1, m);
	return sum;

}

int main() {
	int n, m, d;
	cin >> n >> m >> d;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long res = 0;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		if (a[i] > 0)
			temp = WatchMovie(a, -1, i, n, d, 0, m);
		res = res < temp ? temp : res;
	}
	cout << res << endl;
	cout << "Do you want to try again (Y/n)?:" ;
	getchar();
	return 0;
}