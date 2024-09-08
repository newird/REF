#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n, ans, a, minn;

int main() {
	scanf("%d", &n);
	minn = 100005;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a);
		ans = max(ans, a - minn);
		minn = min(minn, a);
	}
	printf("%d", ans);
	return 0;
} 