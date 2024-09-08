#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	if (n >= 1)
		printf("-1");
	else
	{
		int m = (1 + n) / 2;
		printf("%d", m);
	}
	return 0;
}
