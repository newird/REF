#include<iostream>
#define int long long
using  namespace std;
signed main(){
    int n;
    cin>>n;
    if(n<0){
        puts("-1");
        return 0;
    }
    cout<<n*(n+1)/2<<endl;
    return 0;
}