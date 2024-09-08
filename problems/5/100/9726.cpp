#include<iostream>
using namespace std;
void swap(long long *x,long long *y)
{
	long long temp=*x;
	*x=*y;
	*y=temp;
}
void f(long long a[],long long start,long long end)
{
	long long dad=start;
	long long son=2*dad+1;
	while(son<=end)
	{
		if(son+1<=end && a[son]>a[son+1])
			son++;
		if(a[dad]<=a[son])
			return;
		else
		{
			swap(&a[dad],&a[son]);
			dad=son;
			son=dad*2+1;
		}
	}
}
int main()
{
	long long n,m,d;
	cin>>n>>m>>d;
	long long x[n];
	for(long long i=0;i<n;i++)
	{
		cin>>x[i];
		
	}
	long long y[m]={};
	
	long long c=0;
	long long r=0;
	long long k=0;
	
	for(long long i=0;i<n;i++)
	{	long long q=0;
		if(x[i]>0)
		{
			if(c<m)
			{
				y[0]=x[i];
				f(y,0,m-1);
				c++;
				r+=x[i];
			
			}else
			{
				if(x[i]>y[0])
				{
					long long t=y[0];
					y[0]=x[i];
					f(y,0,m-1);
					r=r-t+x[i];
				}else
				;
			}
		}
					q=r-d*(i+1);
					k=k>q?k:q;
	
	}cout<<k;
 } 