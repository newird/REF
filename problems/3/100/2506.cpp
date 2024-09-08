#include<iostream>
using namespace std;
int n,m,a[100005],b[100005],c[100005];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    int maxn=max(n,m);
    int cf=0,flag=0;
    for(int i=1;i<=maxn;i++){
        c[i]=(cf+a[i]+b[i])%10;
        cf=(cf+a[i]+b[i])/10;
        if(i==maxn&&cf!=0) flag=1;
    }
    if(flag) c[maxn+1]=cf;
    for(int i=maxn+flag;i>=1;i--){
        cout<<c[i];
    }
    return 0;
}