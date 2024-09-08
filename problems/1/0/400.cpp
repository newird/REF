#include<stdio.h>

int main()
{
	int N;
	int s = 0;
	scanf("%d", &N);
	if (N < 1)
	{
		printf("-1");
		return 0;
	}
	else
	{
		for (int i = 1; i <= N; ++i)
		{
			s = s + i;
		}
	}
	printf("%d", s);
	return 0;
}