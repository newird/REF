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

const int N = 100000 + 10;

int n, a[N], pre[N];

int main() {
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	pre[1] = a[1];
	for (int i = 2; i <= n; ++i) pre[i] = min(pre[i - 1], a[i]);
	int ans = 0;
	for (int i = 2; i <= n; ++i) ans = max(ans, a[i] - pre[i]);
	printf("%d\n", ans);
	return 0;
}