#include<stdio.h>

int main() 
{
	long long int n, a;
	a = 0;
	scanf("%lld", &n);
	if (n < 1) {
		printf("-1");
		return 0;
	}
	for (long long int i = 0; i < n; i++) {
		a += i;
	}
	printf("%lld", a);
	return 0;
}