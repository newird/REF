#include <stdio.h>
int main()
{
	int N ; 
	scanf("%d", &N);
        if(N<1)
        {
                printf("-1");
                return 0;
        }
	long long sum = (N+1)*N*0.5;
	printf("%lld", sum);
	return 0;
}
