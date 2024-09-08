#include<stdio.h>
int main() {
	int n = 0, m = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	printf("\n");
	int a[100009] = { 0 };
	int b[100009] = { 0 };
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("\n");
	for (int j = 0; j < m; j++) {
		scanf("%d", &b[j]);
	}
	int c[100009] = { 0 };
	int s = 0;
	for (int k = 0; k < (n > m ? n + 1 : m + 1); k++) {
		c[k] = (a[k] + b[k] + s) % 10;
		if (a[k] + b[k] + s >= 10) {
			s = 1;
		}
		else {
			s = 0;
		}
	}
	if (c[n > m ? n : m ] == 1) {
		printf("1");
	}
	for (int v = (n > m ? n - 1 : m - 1); v >= 0; v--) {
		printf("%d", c[v]);
	}
	return 0;
}