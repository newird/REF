#include<iostream>
using namespace std;
int main()
{
    long long a;
    cin>>a;
    if (a<1) 
       cout<<-1<<endl;
    else
       cout<<a*(a+1)/2<<endl;
    return 0;
}