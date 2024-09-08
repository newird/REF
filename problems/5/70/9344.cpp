#include<iostream>
#include<cstdio>
using namespace std;

int n,m,d,ans=0,heap[205000],treesize=0,cur=0;

void buildtree()
{
	int x=cur;
	
	if(x==1) return;
	int flag=1;
	while(x>1&&flag)
	{
		if(heap[x/2]>heap[x])
		{
			swap(heap[x/2],heap[x]);
		}
		else flag=0;
		x=x/2;
	}
	return;
}

void down(int x)
{
	int flag=1,t=x;
	while(x*2<=cur&&flag)
	{
		if(heap[x*2]<heap[x])
			t=x*2;
		if(x*2+1<=cur&&heap[x*2+1]<heap[t])
			t=x*2+1;
		if(x==t) flag=0;
		else
		{
			swap(heap[x],heap[t]);
			x=t;
		}
	}
	
	
}

int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			if(x>0)
			{
				if(cur==m)
				{
					if(heap[1]<x)
					{
						ans=max(ans,treesize+x-heap[1]-i*d);
						treesize+=x-heap[1];
						heap[1]=x;
						down(1);
					}
				}
				else
				{
					cur++;
					heap[cur]=x;
					buildtree();
					treesize+=x;
					ans=max(ans,treesize-i*d);
				}
			}
		}
	printf("%d\n",ans);
	return 0;
}