#include<stdio.h>
int main()
{
	long long int n,i,sum=0;
	scanf("%lld", &n);
	if (n < 1)
		printf("-1");
	else {
		for (i = 1; i <= n; i++)
		{
			sum += i;
		}
		printf("%lld", sum);
	}
	return 0;
}