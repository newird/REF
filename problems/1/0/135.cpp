#include <stdio.h>
int main()
{
	int N = 0; 
	scanf("%d", &N);
        if(N<1)
        {
                printf("%d", -1);
                return 0;
        }
	int sum =(N+1)*N*0.5;
	printf("%d", sum);
	return 0;
}
