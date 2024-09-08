#include <iostream>

using namespace std;

int n, m, nm, a[10005], b[10005], c, s[10005];

int main() {
	scanf("%d%d", &n, &m);
	nm = max(n, m);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	for (int i=1; i<=m; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= nm; i++) {
		s[i] = (a[i] + b[i] + c) % 10;
		c = (a[i] + b[i] + c) / 10;
	}
	if (c) s[++nm] = c;
	for (int i = nm; i >= 1;i--) printf("%d", s[i]);

}