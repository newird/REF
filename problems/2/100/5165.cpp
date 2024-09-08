#include <iostream>

using namespace std;
int main()
{
    int lst[100005];
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>lst[i];
    }
    int max=0;
    int st[100005];
    int top=0;
    st[0]=lst[0];
    for(int i=1;i<n;++i)
    {
        if(lst[i]>st[top])
        {
            top++;
            st[top]=lst[i];
        }
        else if(lst[i]<st[top])
        {
            max=st[top]-st[0]>max?(st[top]-st[0]):max;
            while(top>=0&&lst[i]<=st[top])
            {
                top--;
            }
            top++;
            st[top]=lst[i];
        }
    }
    max=st[top]-st[0]>max?(st[top]-st[0]):max;
    cout<<max;
    return 0;
}