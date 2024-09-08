#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int len;
	if(n>m)
	
		len=n;
	else
	    len=m;	
	
	int a[100000],b[100000];
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		a[i]=x;		
	}
	for(int i=0;i<m;i++)
		{
			int x;
			scanf("%d",&x);
			b[i]=x;		
		}
for(int i=0;i<len;i++)
{
	a[i]=a[i]+b[i];
	a[i+1]+=a[i]/10;
	a[i]=a[i]%10;
	
}
if(a[len]!=0)
len++;
while(a[len-1]==0&&len>1)
len--;
for(int i=len-1;i>0;i--)
{
	printf("%d",a[i]);
}	
	
}