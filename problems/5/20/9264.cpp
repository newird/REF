#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> max_happiness(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        max_happiness[i] = a[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i && j <= m; j++) {
            max_happiness[i] = max(max_happiness[i], max_happiness[i - j] + a[i - 1] - (long long)d * (i - 1));
        }
    }

    long long result = 0;
    for (int i = 0; i <= n; i++) {
        if (i <= m) {
            result = max(result, max_happiness[i]);
        }
    }

    cout << result << endl;

    return 0;
}
