#include<bits/stdc++.h>
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
int a[100005],b[100005],c[100005];
int x,n,m;
int main(){

	cin>>n>>m;
	
	for(int i =1;i<=n;i++)a[i]=read();	
	for(int i= 1;i<=m;i++)b[i]=read();
	x=0;
	n = max(n,m);
	for(int i = 1;i<=n;i++){
		c[i] = a[i]+b[i]+x;
		x = c[i]/10;
		c[i]%=10;
	}
	if(x==1)c[++n] = 1;
	for(int i=n;i>=1;i--)cout<<c[i];
	cout<<endl;
	
	
	
	
	
	
	return 0;
}