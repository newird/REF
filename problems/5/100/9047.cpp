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

struct Heap {
	int h[N], sz;

	Heap() { memset(h, 0, sizeof(h)), sz = 0; }

	void push(int x) {
		h[++sz] = x;
		int u = sz;
		while (u > 1) {
			int f = u >> 1;
			if (h[f] > h[u]) swap(h[f], h[u]);
			else break;
			u = f;
		}
	}
	int top() { return h[1]; }
	void pop() {
		swap(h[sz], h[1]), --sz;
		int u = 1;
		while ((u << 1) <= sz) {
			int s = u << 1;
			if (s + 1 <= sz && h[s + 1] < h[s]) ++s;
			if (h[s] < h[u]) swap(h[u], h[s]);
			else break;
			u = s;
		}
	}
	int size() { return sz; }
} Q;

int n, m, d, a[N];

int main() {
	n = read(), m = read(), d = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	ll ans = 0, now = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] < 0) continue;
		Q.push(a[i]), now += a[i];
		if (Q.size() > m) now -= Q.top(), Q.pop();
		ans = max(ans, now - 1ll * d * i);
	}
	printf("%lld\n", ans);
	return 0;
}