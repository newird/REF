#include <iostream>
#include <cstdlib>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int max=max(n,m);
    int* num1=new int[max];
    int* num2=new int[max];
    for(int i=0;i<n;++i)
    {
        cin>>num1[i];
    }
    for(int i=0;i<m;++i)
    {
        cin>>num2[i];
    }
    if(n<max)
    {
        for(int i=n;i<max;++i)
            num1[i]=0;
    }
    if(m<max)
    {
        for(int i=m;i<max;++i)
            num2[i]=0;
    }
    int* res=new int[max];
    int carry=0;
    int i;
    for(i=0;i<max(n,m);++i)
    {
        res[i]=(num1[i]+num2[i]+carry)%10;
        if(num1[i]+num2[i]+carry>=10)
        {
            carry=1;
        }
    }
    if(carry)
        cout<<1;
    i--;
    if(!carry)
        while(i>0&&(!res[i]))i--;
    while(i>=0)
    {
        cout<<res[i];
        i--;
    }
    return 0;
}