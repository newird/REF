#include <stdio.h>
int main()
{
	int num1 = 0,sum = 0;
	scanf("%d", &num1);
	if (num1 < 1)
	{
                sum=-1;
	}
	else
	{
		while (num1>=1)
		{
			sum = num1+sum;
			num1--;
		}
	}
	printf("%d", sum);
	return 0;
}