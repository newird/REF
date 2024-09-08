#include<stdio.h>

int main()
{
	int n;
	int P[20], p[20];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &P[i]);
	}
	for (int j = 0; j < n; j++) {
		int h1 = 0;
		for (int k = j + 1; k < n; k++) {
			int h2 = P[k] - P[j];
			if (h2 > h1) h1 = h2;
		}
		p[j] = h1;
	}
	int res = p[1];
	for (int m = 1; m < n; m++) {
		if (p[m] > res)res = p[m];
	}
	printf("%d", res);
	return 0;
}