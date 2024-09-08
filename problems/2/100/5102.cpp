#include<iostream>
#include<cstdio>
using namespace std;

int n,minn=2147483646,a,ans=0;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(i==1)
		{
			minn=a;
		}
		else{
			ans=max(ans,a-minn);
		}
		minn=min(minn,a);
	}
	
	cout<<ans<<"\n";
	return 0;
}