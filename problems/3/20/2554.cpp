#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n ;
    cin >> m;
    int arr1[n]{};
    int arr2[m]{};
    int k = (n >= m ? n : m);
    int arr3[k]{};
    int cinf = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    for (int i = 0; i < k; i++) {
        if (i < m && i < n)arr3[i] = arr1[i] + arr2[i] + cinf;
        else if (i < m) arr3[i] = arr2[i] + cinf;
        else arr3[i] = arr1[i] + cinf;
        if (arr3[i] > 9) { arr3[i] -= 10; cinf = 1; }
        else cinf = 0;
    }
    if (cinf == 1)cout << 1;
    for (int i = 0; i < k; i++) {
        cout << arr3[i];
    }
}