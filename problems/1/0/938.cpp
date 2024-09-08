#include <stdio.h>

int main() {
    int N;
    int sum = 0;
    scanf("%d", &N);
    if (N < 1) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= N; ++i) {
        sum += i;
    }


    printf("%d\n", sum);
    return 0;
}