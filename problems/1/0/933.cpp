#include<stdio.h>
int main(){
  int N;
  long long sum=0;
  scanf("%d",&N);
  if(N<1){printf("-1\n");}
  for(int i=1;i<=N;++I){
	  sum+=i;}
  if(N>=1){printf("%d\n",sum);}
  return 0;
}	