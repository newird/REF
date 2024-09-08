#include<iostream>
int main()
{
	int a;
	long long sum = 0;
	scanf("%d", &a);
	if (a < 1)
	{
		printf("-1");
		return 0;
	}
	for (int i = 0; i <= a; ++i)
	{
		sum += i;
	}
	printf("%lld", sum);
	return 0;
}
