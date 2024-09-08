#include<iostream>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    if(n<1)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    long long sum=0;
    for(long long i=1;i<=n;i++)
    {
        sum+=i;
    }
    cout<<sum<<endl;
}
