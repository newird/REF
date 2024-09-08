#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void f(int a[],int start,int end)
{
	int dad=start;
	int son=2*dad+1;
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
	int n,m,d;
	cin>>n>>m>>d;
	int x[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
		
	}
	int y[m]={};
	
	int c=0;
	int r=0;
	int k=0;
	
	for(int i=0;i<n;i++)
	{	int q=0;
		if(x[i]>0)
		{
			if(c<m)
			{
				y[0]=x[i];
				f(y,0,m-1);
				c++;
				r+=x[i];
				
				q=r-d*(i+1);
				k=k>q?k:q;
			
			}else
			{
				if(x[i]>y[0])
				{
					int t=y[0];
					y[0]=x[i];
					f(y,0,m-1);
					r=r-t+x[i];
					q=r-d*(i+1);
					k=k>q?k:q;
				}else
				;
			}
		}
	
	}cout<<k;
 } 