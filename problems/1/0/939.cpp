#include<stdio.h>
int main(){
  int N;
  int i=1;
  long long sum=0;
  scanf("%d",&N);
  if(N<1)
  {printf("-1\n");}
  while(i<=N){
	  sum=sum+i;
	  i=i+1;}
  if(N>=1)
  {printf("%d",sum);}
  return 0;
} 