#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    if(N>1)
        cout << N*(N+1)/2;
    else
        cout << -1;
    
}
