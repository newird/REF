#include<iostream>
#include<cstdio>
#define max_n 100500
using namespace std;

int n,m,a[max_n],b[max_n],c[max_n];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	int l=max(n,m);
	int ans=l;
	for(int i=1;i<=l;i++)
	{
		c[i]+=(a[i]+b[i]);
		if(c[i]>9&&l==i) ans++;
		c[i+1]+=c[i]/10;
		c[i]=c[i]%10;
	}
	for(int i=ans;i>=1;i--)
		cout<<c[i];
	return 0;
}