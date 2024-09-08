#include <stdio.h>

int main() {
    int n , m;
    scanf("%d %d",&n, &m);
    int first[n], second[m];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &first[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &second[i]);
    }
    int result[n > m ? n+1 : m+1];
    for (int i = 0; i < n + 1 || i < m + 1;++i) {
        result[i] = 0;
    }
    int signal = 0;
    int i = 0;
    for (; i <n && i < m; ++i) {
        int sum = signal + first[i] + second[i];
        signal = sum / 10;
        if (sum >= 10) {
            result[i] = sum % 10;
        } else {
            result[i] = sum;
        }
    }
    while (i < n) {
        int sum = signal + first[i];
        signal = sum / 10;
        if (sum > 10) {
            result[i++] = sum % 10;
        } else {
            result[i++] = sum;
        }
    }
    while (i < m) {
        int sum = signal + second[i];
        signal = sum / 10;
        if (sum > 10) {
            result[i++] = sum % 10;
        } else {
            result[i++] = sum;
        }
    }
    int temp = n > m ? n + 1 : m + 1;
    result[temp - 1] = signal;
    for (int i = temp - 1;i >= 0; --i) {
        if (i == temp - 1 && result[i] == 0) {
            continue;
        }
        putchar(result[i] + '0');
    }
    putchar('\n');
    return 0;
}