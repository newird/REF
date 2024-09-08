#include<iostream>
using namespace std;
void siftDown(int start,int m,int *heap)
{
	int i=start,j=2*i+1;
	int temp=heap[i];
	while(j<=m)
	{
		if(j<m &&heap[j]>heap[j+1])
		j++;
		if(temp<=heap[j])
		break;
		else
		{
			heap[i]=heap[j];
			i=j;
			j=2*j+1;
		}
	}
	heap[i]=temp;
}
int main()
{
	int n,m,d;
	cin>>n>>m>>d;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int maxh=0;
	while(m>0)
	{

		//看m天电影 
		int heap[m];
		int maxsum=0;
		for(int i=0;i<m;i++)
		{
			heap[i]=a[i];
			maxsum+=a[i];
		} 
		maxsum-=m*d;//维护一个最大幸运值 
		int currentSize=m;
		int currentPos=(currentSize-2)/2;
		while(currentPos>=0)
		{
			siftDown(currentPos,currentSize-1,heap);
			currentPos--;
		}//自下向上调整为最小堆 
		int flag=m-1;
		for(int i=m;i<n;i++)
		{
			if(a[i]<heap[0]+(i-flag)*d)
			{
				continue;
			}
			else
			{
				
				maxsum=maxsum-heap[0]+a[i]-(i-flag)*d;
				flag=i;
				heap[0]=a[i];
				siftDown(0,m-1,heap);
			}
		}

		maxh=max(maxh,maxsum);
		m--; 
	}
	//维护一个m大小的最小堆
	maxh=max(0,maxh);
	cout<<maxh;
	
 } 