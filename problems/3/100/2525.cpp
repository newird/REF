#include<iostream>
#include<cstdio>

using namespace std;

int n, m, l, a[100005], b[100005];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	l = max(m, n);
	for(int i = 1; i <= l; i++) {
		a[i] += b[i];
		if(a[i] > 9) {
			a[i] -= 10;
			a[i + 1] += 1;
		}
	}
	l = a[l + 1] ? l + 1 : l;
	for(int i = l; i; i--)
		printf("%d", a[i]);
	return 0;
}