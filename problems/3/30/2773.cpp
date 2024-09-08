#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	
	int x[n];
	int y[m];
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>y[i];
	}int s1=0;
	int s2=0;
	for(int i=n-1;i>=0;i--)
	{
		s1=10*s1+x[i];
	}
	for(int i=m-1;i>=0;i--)
	{
		s2=10*s2+y[i];
	}cout<<s1+s2; 

	
}