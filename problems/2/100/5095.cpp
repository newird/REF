#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int minn=0xffffff,ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,a[i]-minn);
        minn=min(minn,a[i]);
    }
    cout<<ans<<endl;
    return 0;
}