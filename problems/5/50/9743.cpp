#include <iostream>
using namespace std;

#define N 200000

int main() {
    long long int n, m, d, arr[N];
    cin >> n >> m >> d;

    long long int sum = 0;
    long long int y = 0;

    for (long long int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (long long int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            if (i < m) {
                sum += arr[i];
            }
            else {
                long long int max_in_window = arr[i];
                for (int j = i - 1; j >= i - m; j--) {
                    max_in_window = max(max_in_window, arr[j]);
                }
                sum = max_in_window;
            }
            y = max(y, sum - d * (i + 1));
        }
    }

    cout << y << endl;

    return 0;
}