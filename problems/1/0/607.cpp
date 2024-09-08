#include<iostream>
int main()
{
	int N;
	long long sum = 0;
	scanf("%d", &N);
	if (N < 1)
	{
		printf("-1");
		return 0;
	}
	for (int i = 0; i <= N; ++i)
	{
		sum += i;
	}
	printf("%lld", sum);
	return 0;
}
