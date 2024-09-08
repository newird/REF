#include <iostream>
using namespace std;

int pow(int n, int j)
{
    int res = 1;
    for (int i = 0; i < j; i++)
    {
        res = res * n;
    }
    return res;
}

int main() {
    
    int a,b,inita,initb;
    int ansa = 0;
    int ansb = 0;
    cin >> a >> b;
    
    inita = a;
    initb = b;

    int arraya[a]; // xcode -> int array[a]; 선언가능
    int arrayb[b]; // xcode -> int array[a]; 선언가능

    while (a--)
    {
        int t;
        cin >> t;
        arraya[a] = t;
    }a++;

    for (int i = inita; 0 < i; i--)
    {
        ansa += arraya[a] * pow(10, i - 1);
        a++;
    }

    while (b--)
    {
        int t;
        cin >> t;
        arrayb[b] = t;
    }b++;

    for (int i = initb; 0 < i; i--)
    {
        ansb += arrayb[b] * pow(10, i - 1);
        b++;
    }

    cout << ansa+ansb << endl;
    return 0;
}

