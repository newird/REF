#include <stdio.h>
int main()
{
	int num1 = 0;
        long long sum = 0;
	scanf("%d", &num1);
	if (num1 < 1||num1>=20000000)
	{
                printf("-1");
		return 0;
	}
	else
	{
		while (num1>=1)
		{
			sum = num1+sum;
			num1--;
		}
	}
	printf("%lld", sum);
	return 0;
}