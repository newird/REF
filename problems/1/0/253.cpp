#include<stdio.h>

int main()
{
int n;
scanf("%d",&n);
long long int sum=0;
if(n<1)
{
	sum=-1;
	printf("%d",sum);
}
else
{
	while (n>0)
	{
		sum=sum+n;
		n-=1;
		
	}printf("%d",sum);
}return 0;
}