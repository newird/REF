#include<stdio.h>

int main(){
	int n ;
	scanf("%d",&n) ;
	if(n < 1 ) {
		puts("-1");
	}else{
		printf("%lld\n" , 1ll*n*(n+1)/2) ;
	}
	return 0 ;
}