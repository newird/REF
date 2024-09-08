#include <stdio.h>
int main()
{
	int n ; 
	scanf("%d", &n);
        if(n<1)
        {
                printf( "-1");
                return 0;
        }
	long long sum = (n+1)*n*0.5;
	printf("%lld", sum);
	return 0;
}