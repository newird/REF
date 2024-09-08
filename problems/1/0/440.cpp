#include <stdio.h>
int main() {
	long long a;
	long long b=0;
	scanf("%d", &a);
	if (a < 1) b = -1;
	else {
		for (int i = 1; i <= a; i++) {
			b = b + i;
		}
	}
	printf("%d", b);
}