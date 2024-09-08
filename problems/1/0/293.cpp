#include<stdio.h>
int main()
{
	int n,i,sum=0;
	scanf("%d", &n);
	if (n < 1)
		printf("-1");
	else {
		for (i = 1; i <= n; i++)
		{
			sum += i;
		}
		printf("%d", sum);
	}
	return 0;
}