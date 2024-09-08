#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);

if(n<1)
printf("-1");

else
{long long int sum=0;
	while(n>0)
	{
		sum=sum+n;
		n-=1;
	}printf("%d",sum);
}

}