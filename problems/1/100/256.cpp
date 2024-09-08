#include <iostream>
using namespace std;

int main(){
    long N;
    cin >> N;
    if(N>1)
        cout << N*(N+1)/2;
    else
        cout << -1 << endl;
    
}

