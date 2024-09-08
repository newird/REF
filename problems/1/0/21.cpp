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
sum = (long long int)(N*(N+1)/2);
}
printf("%d",sum);
}