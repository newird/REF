#include<stdio.h>

int main( void ) {
    int n;
    long long Sn = 0;

    scanf("%d", &n);
if(n<1){
		printf("-1");
		return 0;
}
    for( long long  num = 1, num1 = 1; n > 0; n-- ){
        Sn += num *num1;
        num1 *= num;
        num++;
    }
    printf("%lld\n", Sn);

    return 0;
}
