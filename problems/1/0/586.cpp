#include<stdio.h>
int main(){
	long long a;
	long long b;
	scanf("%d",&b);
	if(b>=1){a=(b+1)*b/2;}
	if(b<1){a=-1;}
	printf("%d",a);
	return 0;
}	