#include<stdio.h>
int main()
{
	int n;
	long long sum = 0;
	scanf("%d", &n);
	if (n < 1)
	{
		printf("-1");
		return 0;
	}
	sum=n*(n+1)*0.5;
	printf("%lld", sum);
	return 0;
}

