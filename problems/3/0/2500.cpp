#include <iostream>
#include <cstdlib>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int* num1=new int[n];
    int* num2=new int[m];
    for(int i=0;i<n;++i)
    {
        cin>>num1[i];
    }
    for(int i=0;i<m;++i)
    {
        cin>>num2[i];
    }
    int* res=new int[max(n,m)];
    int carry=0;
    int i;
    for(i=0;i<max(n,m);++i)
    {
        if(num1[i]+num2[i]+carry>=10)
        {
            carry=1;
        }
        res[i]=(num1[i]+num2[i]+carry)%10;
    }
    res[i]=carry;
    while(i>0&&!res[i])i--;
    while(i>=0)
    {
        cout<<res[i];
        i--;
    }
    return 0;
}