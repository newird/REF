#include<stdio.h>
int main()
{
long long int N;
scanf("%d",&N);
long long int sum=0;
if(N<1)
    sum=-1;
else
{
int i=0;
for(i=0;i<=N;i++)
{
sum+=i;
}
}
printf("%d",sum);
}