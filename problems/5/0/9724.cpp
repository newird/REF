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
	int heap[m];
	int size=0;
	int lastwatch=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]<0)
	        continue;
	    else
	    {
	    	if(a[i-1]>0 && size<m)
	    	{
	    		heap[size]=a[i-1];
	    		lastwatch=i;
	    		size++;
	    		siftDown(0,size-1,heap);
				for(int j=0;j<size;j++)
				{
					cout<<heap[j]<<" ";
				}   		
				cout<<endl;
			}
			else if(a[i-1]-(i-lastwatch)*d>0 )
			{
				if(a[i-1]>heap[0])
				{
					heap[0]=a[i-1];
					lastwatch=i;
					siftDown(0,size-1,heap); 
				}
				for(int j=0;j<size;j++)
				{
					cout<<heap[j]<<" ";
				}   		
				cout<<"type2"<<endl;
			}
			else
			{
				continue;
			}
		}
	}
	int sum=0;
	for(int i=0;i<size;i++)
	{
		sum+=heap[i];
	}
	sum-=lastwatch*d;
	cout<<(sum<0? 0:sum);
	
	
	
 } 