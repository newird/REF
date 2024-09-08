#include<stdio.h>
int main()
{
	int n, m, i, j, k, a[10010] = { 0 }, b[10010] = { 0 }, c[10010] = { 0 };
	scanf("%d %d\n", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (i != n)
			scanf(" ");
	}
	scanf("\n");
	for (j = 1; j <= m; j++)
	{
		scanf("%d", &b[j]);
		if (j != m)
			scanf(" ");
	}
	for (k = 1; k <= ((m>=n)?m:n); k++)
	{
		c[k] += a[k] + b[k];
		c[k] = c[k] % 10;
		c[k + 1] += (a[k]+b[k])/10;
	}
	if (c[k] == 0)
		k -= 1;
	for (i = k; i >= 1; i--)
	{
		printf("%d", c[i]);
	}
	return 0;
}