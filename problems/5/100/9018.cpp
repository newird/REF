#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int res=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')res=res*10+ch-48,ch=getchar();
	return res*f;
}
int a[200005],d,ans;
priority_queue<int,vector<int>,greater<int> > q;
int l,r,sum,n,m;
signed main(){
	n=read();
	m=read();
	d=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i = 1;i<=n;i++){
		if(a[i]>0){
			q.push(a[i]);
			sum+=a[i];
		}
		while(1ll*q.size()>m*1ull){
			sum-=q.top();
			q.pop();
		}
		ans= max(sum-i*d,ans);
	}
	cout<<ans<<endl;

	
	return 0;
}