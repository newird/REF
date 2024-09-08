#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;

int read() {
	int X = 0, w = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') w = -1; c = getchar(); }
	while (c >= '0' && c <= '9') X = X * 10 + c - '0', c = getchar();
	return X * w;
}

const int N = 200000 + 10;

int n, m, d;
int a[N];

ll f[N], ans;
int b[N], c[N], cnt;
void calc(int k) {
	for (int i = 1; i <= n; ++i) b[i] = a[i] - k;
	f[0] = 0, c[0] = 0; int maxp = 0;
	for (int i = 1; i <= n; ++i) {
		f[i] = f[maxp] + b[i] -  1ll * d * (i - maxp);
		c[i] = c[maxp] + 1;
		if (f[i] + 1ll * d * i > f[maxp] + 1ll * d * maxp) maxp = i;
	}
	maxp = 0;
	for  (int i = 1; i <= n; ++i)
		if (f[i] > f[maxp] || (f[i] == f[maxp] && c[i] < c[maxp])) maxp = i;
	ans = f[maxp], cnt = c[maxp];
}

int main() {
	n = read(), m = read(), d = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	int L = 0, R = m;
	while (L < R) {
		int mid = (L + R) >> 1;
		calc(mid);
		if (cnt <= m) R = mid;
		else L = mid + 1;
	}
	calc(L);
	printf("%lld\n", ans + 1ll * d * L);
	return 0;
}