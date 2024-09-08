#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a1,a2;
    double temp,res1=0,res2=0;
    cin >> a1;
    cin >> a2;
    for(int i=0;i<a1;++i)
    {
        cin >> temp;
        res1 = res1 + temp * pow(10,i);
    }
    for (int i = 0; i < a2; ++i)
    {
        cin >> temp;
        res2 = res2 + temp * pow(10, i);
    }
    cout<<res1+res2;
    return 0;
}