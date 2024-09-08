#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n<1)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=i;
    }
    cout<<sum<<endl;
}
