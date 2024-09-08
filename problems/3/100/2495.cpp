#include <cstdio>

const int N = 100007;
inline int max(int x, int y) { return x > y ? x : y; }

int n, m, a[N], b[N], c[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
	int mxlen = max(n, m);
	for (int i = 1; i <= mxlen; ++i) c[i] = a[i] + b[i];
	for (int i = 1; i <= mxlen; ++i) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	if (c[mxlen + 1] > 0) ++mxlen;
	for (int i = mxlen; i >= 1; --i) printf("%d", c[i]);
	return 0;
}