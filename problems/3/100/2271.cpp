#include <iostream>

using namespace std;

void add(int *a, int *b, int len1, int len2) {
    int c = 0;

    for (int i = 0; i < len1; i++) {
        int sum = a[i] + b[i] + c;
        c = sum / 10;
        b[i] = sum % 10;

    }
    for (int i = len1; i < len2; i++) {
        int sum = b[i] + c;
        c = sum / 10;
        b[i] = sum % 10;
    }
    b[len2] += c;
    int strLen = c == 1 ? len2 : len2 - 1;
    for (int i = strLen; i >= 0; i--)cout << b[i];
}

int main() {
    int n, m;
    cin >> n >> m;
    int a[n + 1], b[m + 1];
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < m; i++)cin >> b[i];
    a[n] = b[m] = 0;
    if (n < m)add(a, b, n, m);
    else add(b, a, m, n);
    return 0;
}

