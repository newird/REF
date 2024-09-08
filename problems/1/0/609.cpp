#include<stdio.h>
int main(){
	long long a;
	long  b;
	scanf("%d",&b);
	if(b<1){a=-1;}
	for(int i=0;i<b;i++;){
		a=a+b;
		b=b-1;}
	
	printf("%d",a);
	return 0;
}	