#include<stdio.h>
int main()
{int n,a[100000];
scanf("%d",&n);
int x;
for(int i=0;i<n;i++)
{
	scanf("%d",&x);	
	a[i]=x;
}	
int stk[100000]={0};
int ans;
int top=0;
stk[top]=a[0];
for(int i=0;i<n-1;i++)
{if(a[i+1]<stk[0]&&a[i+1]<a[i])
{top=0;
	stk[top]=a[i+1];
}
else if(a[i+1]>=stk[0]&&a[i+1]>=stk[top])
{
	top++;
	stk[top]=a[i+1];
}

}
ans=stk[top]-stk[0];
printf("%d ",ans);
}
