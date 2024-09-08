#include <stdio.h>
int main()
{
	int N = 0; 
	scanf("%d", &num1);
        if(N<1)
        {
                printf("%d", -1);
                return -1;
        }
	int sum =(N+1)*N*0.5;
	printf("%d", sum);
	return 0;
}
