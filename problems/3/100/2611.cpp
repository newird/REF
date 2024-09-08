#include <iostream>
#include <stdio.h>
using namespace std;

int a[100005] = { 0 };

int MyMax(int a, int b) {
    return (a > b) ? a : b;
}


int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int n2;
        cin >> n2;
        if (a[i] + n2 > 9) {
            int j = 1;
            a[i + j]++;
            while (a[i + j] > 9) {
                a[i + j + 1]++;
                a[i + j] = 0;
                j++;
            }
        }
        a[i] = (a[i] + n2) % 10;
    }
    int Mylegth = MyMax(m, n);
    Mylegth = (a[Mylegth] == 0) ? Mylegth-1 : Mylegth;
    for (int i = Mylegth; i >= 0; i--) printf("%d", a[i]);

}