#include<stdio.h>
int main(){
  int N;
  long long sum=0;
  scanf("%d",&N);
  if(N<1){printf("-1");}
  for(int i=1;i<=N;i++){
	  sum+=i;}
  if(N>=1){printf("%d",sum);}
  return 0;
}	