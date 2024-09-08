#include<stdio.h>

int main()
{
	int n;
	int P[100000], p[10000] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &P[i]);
	}
	int h0 = P[0];
	int a = 0;
	for (int m = 1; m < n; m++) {
		if (P[m] > h0) {
			a = m;
			h0 = P[m];
		}
	}
	int h1 = h0;
	for (int j = 0; j < n; j++) {
		if (j > a) {
			h1 = P[j];
			for (int k = j + 1; k < n; k++) {
				if (P[k] > h1) h1 = P[k];
			}
		}
		p[j] = h1 - P[j];
	}
	int res = p[1];
	for (int m = 1; m < n; m++) {
		if (p[m] > res)res = p[m];
	}
	printf("%d", res);
	return 0;
}