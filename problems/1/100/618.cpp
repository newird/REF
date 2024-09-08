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
	for (int i = 0; i <= n; ++i)
	{
		sum += i;
	}
	printf("%lld", sum);
	return 0;
}
