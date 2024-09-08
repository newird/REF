#include <iostream>
#include <algorithm>
using namespace std;


int main(){
 long long N;
 cin>>N;
 if(N<1){
    cout<<-1;
 }
 else{
    long long s=0;
    for(long long i=1;i<=N;i++){
        s+=i;
    }
    cout<<s;
 }
 return 0;
}