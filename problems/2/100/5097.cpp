#include <cstdio>

int n, a, mi, ans;

int main() {
    ans = 0, mi = (1 << 30);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        if (a - mi > ans) ans = a - mi;
        if (a < mi) mi = a;
    }
    printf("%d\n", ans);
    return 0;
}