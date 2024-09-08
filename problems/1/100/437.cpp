#include<stdio.h>
int main()
{
	int n; long long re=0;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i)
	{
		re += i;
    }
	if (n < 1)
		printf("-1");
	else
		printf("%lld", re);
	return 0;
}