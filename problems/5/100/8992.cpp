#include <cstdio>
#include <cstring>

typedef long long ll;
const int N = 200007;

int n, m, len;
ll ans, ret, h[N], a[N], d;

ll max(ll a, ll b) {
	return a > b ? a : b;
}

void swap(ll &a, ll &b) {
	ll t = a;
	a = b;
	b = t;
}

void push(ll x) {
	if (x > 0) ret += x;
	h[++len] = x;
	int now = len;
	while (now > 1) {
		if (h[now] < h[now / 2]) {
			swap(h[now], h[now / 2]);
			now /= 2;
		} else break;
	}
}

void pop() {
	if (h[1] > 0) ret -= h[1];
	h[1] = h[len--];
	int now = 1, nxt;
	while (now * 2 <= len) {
		nxt = now * 2;
		if (nxt < len && h[nxt + 1] < h[nxt]) ++nxt;
		if (h[nxt] < h[now]) {
			swap(h[nxt], h[now]);
			now = nxt;
		} else break;
	}
}

int main() {
	scanf("%d%d%lld", &n, &m, &d);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	ans = 0, ret = 0;
	for (int i = 1; i <= m - 1; ++i) {
		ans = max(ans, ret + a[i] - d * i);
		push(a[i]);
	}
	for (int i = m; i <= n; ++i) {
		ans = max(ans, ret + a[i] - d * i);
		if (a[i] > h[1]) {
			pop();
			push(a[i]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}