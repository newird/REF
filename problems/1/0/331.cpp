#include <cstdio>

ll n, ans;

int main() {
	scanf("%lld", &n);
	if (n < 1) printf("-1\n");
	else {
		ans = n * (n + 1) / 2;
		printf("%lld\n", ans);
	}
	
	return 0;
}