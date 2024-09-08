#include<stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	if (a < -1) {
		printf("-1");
	}
	else {
		long long int b;
		b = a * (a + 1) / 2;
		printf("%lld", b);
	}
	return 0;
}