#include<iostream>
using namespace std;
int main(){
 int N;
 int sum=0;
 cin >> N;
 if(N<1)
  cout << -1;
 int i=1;
 while(i<=N){
  sum=sum+i;
  i++;
 }
if(N>=1)
cout << sum;
return 0;
}