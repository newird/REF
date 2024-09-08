#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int maxLen = max(n, m);

    int *a = new int[maxLen];
    int *b = new int[maxLen];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int carry = 0;
    int *result = new int[maxLen + 1]; // +1 to account for potential carry in the most significant digit

    for (int i = 0; i < maxLen + 1; i++) {
        result[i] = 0; // Initialize all elements to zero
    }

    for (int i = 0; i < maxLen; i++) {
        int sum = carry;
        if (i < n) {
            sum += a[i];
        }
        if (i < m) {
            sum += b[i];
        }
        result[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0) {
        result[maxLen] = carry;
        maxLen++;
    }

    // Print the result in reverse order
    for (int i = maxLen - 1; i >= 0; i--) {
        cout << result[i];
    }

    cout << endl;

    delete[] a;
    delete[] b;
    delete[] result;

    return 0;
}
