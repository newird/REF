#include<stdio.h>
int main()
{int n,a[100000],x;
scanf("%d",&n);
for(int i=0;i<n;i++)
{
	a[i]=scanf("%d",&x);	
}	
int max=0;
for(int i=0;i<n-1;n++)	
{for(int j=1;j<n;j++)
	
if(	a[j]-a[i]>max)
{
	max=a[j]-a[i];
}
	
}	
	
printf("%d",max);	
	
}
