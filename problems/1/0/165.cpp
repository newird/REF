#include<iostream>
using namespace std;
int main(){
 int N;
 int sum=0;
 cin >> N;
 if(N<1)
 return -1;
 int i=1;
 while(i<=N){
  sum=sum+i;
  i++;
 }
cout << sum;
return 0;
}