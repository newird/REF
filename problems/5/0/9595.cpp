#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n, greater<int>()); // 按幸福值从大到小排序

    int happiness = 0;
    int nextDay = 0;
    for (int i = 0; i < m; i++) {
        happiness += a[i];
        nextDay += d;
    }

    cout << happiness << endl;

    delete[] a;
    return 0;
}