#include<stdio.h>

int main() {
	long long int a;
	scanf("%lld", &a);
	if (a < 1) {
		printf("-1");
	}
	else {
		long long int b;
		b = a * (a + 1) / 2;
		printf("%lld", b);
	}
	return 0;
}