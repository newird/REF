#include<stdio.h>

int main()
{
	long long N;
	long long s = 0;
	scanf("%lld", &N);
	if (N < 1)
	{
		printf("-1");
		return 0;
	}
	else
	{
		for (long long i = 1; i <= N; ++i)
		{
			s = s + i;
		}
	}
	printf("%lld\n", s);
	return 0;
}