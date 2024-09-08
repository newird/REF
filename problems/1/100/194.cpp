#include<iostream>
using namespace std;
int main(){
 long long int N;
 long long int sum=0;
 cin >> N;
 if(N<1)
  cout << -1;
 long long int i=1;
 while(i<=N){
  sum=sum+i;
  i++;
 }
if(N>=1)
cout << sum;
return 0;
}