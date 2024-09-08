#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);

if(n<1)
printf("-1");

else
{long long int sum=0;
for(int i=n;i>0;i--)
sum+=i;
	printf("%d",sum);
}

}