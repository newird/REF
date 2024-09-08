#include<stdio.h>
int main()
{
int N;
scanf("%d",&N);
int sum=0;
if(N<1)
    sum=-1;
else
{
int i;
for(i = 0; i<=N; i++)
    sum+=i;
}
printf("%d",sum);
}