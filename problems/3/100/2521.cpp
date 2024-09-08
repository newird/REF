#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;

const int N = 200000 + 10;

int n, m, a[N], b[N], c[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= m; ++i) scanf("%d", b + i);
	int l = max(n, m);
	for (int i = 1; i <= l; ++i) c[i] = a[i] + b[i];
	for (int i = 1; i <= l; ++i)
		if (c[i] >= 10) c[i + 1] += c[i] / 10, c[i] %= 10;
	while (c[l + 1]) ++l;
	for (int i = l; i; --i) putchar(c[i] + '0');
	puts("");
	return 0;
}