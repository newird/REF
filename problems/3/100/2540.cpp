#include<iostream>
using namespace std;
int main()
{
	int n,m;
	int helper,flag=0;
	cin>>n>>m;
	int a[n],b[m];
	int c[n+m];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<m && i<n;i++)
	{
		if(flag==1)
		{
			helper=(a[i]+b[i]+1)%10;
			if(a[i]+b[i]+1>=10)
		       flag=1;
		    else
		       flag=0;
		}
		else
		{
			helper=(a[i]+b[i])%10;
			if(a[i]+b[i]>=10)
		       flag=1;
		    else
		       flag=0;
		}
		c[i]=helper;
	}
	if(m==n)
	{
		if(flag==1)
		{
			c[m]=1;
			for(int i=m;i>=0;i--)
			    cout<<c[i];
		}
		else
		{
			for(int i=m-1;i>=0;i--)
			    cout<<c[i];
		}
	}
	else if(m>n)
	{
		for(int i=n;i<m;i++)
		{
			if(flag==1)
			{
				helper=(b[i]+1)%10;
				if(b[i]+1>=10)
			       flag=1;
			    else
			       flag=0;
			}
			else
			{
				helper=b[i];
                flag=0;
			}
			c[i]=helper;
		}
		if(flag==1)
		{
			c[m]=1;
			for(int i=m;i>=0;i--)
			    cout<<c[i];
		}
		else
		
		{
			for(int i=m-1;i>=0;i--)
			    cout<<c[i];
		}
	}
	else
	{
		for(int i=m;i<n;i++)
		{
			if(flag==1)
			{
				helper=(a[i]+1)%10;
				if(a[i]+1>=10)
			       flag=1;
			    else
			       flag=0;
			}
			else
			{
				helper=a[i];
                flag=0;
			}
			c[i]=helper;
		}
		if(flag==1)
		{
			c[n]=1;
			for(int i=n;i>=0;i--)
			    cout<<c[i];
		}
		else
		
		{
			for(int i=n-1;i>=0;i--)
			    cout<<c[i];
		}
	}

}
