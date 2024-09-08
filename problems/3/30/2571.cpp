#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a=n>m?n:m;
	int x[a];
	int y[a];
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>y[i];
	}
	if(n < m)
	{
		for(int i=n;i<m;i++)
		x[i]=0;
	}
	else if(m<n)
	{
		for(int i=m;i<n;i++)
		y[i]=0;
	}
	else
	;
	int z[a+1];
	z[0]=0;
	int b[a];
	for(int i=0;i<a;i++)
	{
		b[i]=x[i]+y[i]+z[i];
		if(b[i]>=10)
		{
			b[i]-=10;
			z[i+1]=1;
		}
		else
		z[i+1]=0;
	}long long int s=z[a];
	for(int i=a-1;i>=0;i--)
	{
		s=s*10+b[i];
	}cout<<s<<endl;
	
	
}