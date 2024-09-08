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
	sum=(1+n)*n/2;
	printf("%d",sum);
}
}