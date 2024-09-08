#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int max=0;
    int* min = new int[n];
    int temp;
    int i = 0;
    cin >> min[0];
    for (i = 1; i < n; i++) {
        cin >> temp;
        min[i]= (temp < min[i - 1]) ? temp : min[i - 1];
        if (temp - min[i - 1] > max) max = temp - min[i - 1];
    }
    cout << max << endl;
    delete[] min;
    return 0;
}
