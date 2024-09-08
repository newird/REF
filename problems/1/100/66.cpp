#include<stdio.h>
int main(){
    long long int a;
    long long int result;
    scanf("%lld", &a);
    result = a * (a+1) / 2;
    if(a <= 0){
        result = -1;
    }
    printf("%lld" , result);
    return 0;
}