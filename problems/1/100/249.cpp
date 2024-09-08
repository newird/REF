#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;

int main() {
	int n; scanf("%d", &n);
	if (n < 1) puts("-1");
	else printf("%lld\n", 1ll * n * (n + 1) / 2);
	return 0;
}