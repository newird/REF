#include<stdio.h>

int main( void ) {
    int n;
    long long Sn = 0;

    scanf("%d", &n);
if(n<1){
		printf("-1");
		return 0;
}
   Sn = ((1 + n) * n) / 2;
printf("%lld\n", Sn);
    printf("%lld\n", Sn);
    return 0;
}
