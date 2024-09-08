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
    int result=0; 
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]<0)
	        continue;
	    else
	    {
	    	if(a[i-1]>0 && size<m)
	    	{
	    		heap[size]=a[i-1];
	    		result+=a[i-1];
	    		lastwatch=i;
	    		size++;
			}
			else if(a[i-1]>0 )
			{
				siftDown(0,size-1,heap);
				if(a[i-1]>heap[0])
				{
					if(result-lastwatch*d<result-heap[0]+a[i-1]-i*d)
					    result+=a[i-1]-heap[0];
					heap[0]=a[i-1];
					lastwatch=i;
				}
				else 
				    continue;
			}
			else
			{
				continue;
			}
		}
	}

	cout<<(result-lastwatch*d<0? 0:result-lastwatch*d);
	
	
	
 } 