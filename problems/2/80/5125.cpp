#include<stdio.h>
int main() {
	int n;
	scanf("%d\n", &n);
	int a[100001] = { 0 };
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int max = 0;
	int t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[j] > a[i]) {
				t = a[j] - a[i];
			}
			else;
			if (t > max) {
				max = t;
			}
			else;
		}
	}
	printf("%d", max);
	return 0;
}