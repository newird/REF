#include<iostream>
using namespace std;
int main()
{
int n;
long long int sum=0;
cin>>n;
if(n<1)
cout<<"-1";
else
{
while (n>0)
{sum+=n;
n-=1;
}cout<<sum;


}}

