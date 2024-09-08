#include <iostream>
#include <string>

using namespace std;

void swap(int a[], int i, int j){
	int tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
}

int maxk(int a[], int k, int n, int d){
	int heap[k];
	int maxi=-1;
	int heapl=0;
	for(int i=0;i<n;i++){
		int tmp=a[i];
		cout<<tmp<<' '<<heapl<<endl;
		if(heapl<k){
			if(tmp-d*(i-maxi)>0){
				heap[heapl++]=tmp;
				maxi=i;
				//满了，调整堆 
				if(heapl==k){
					for(int p=0;p<k;p++){
						int j=p;
						//建堆，往上调整 
						while(heap[(j-1)/2]>heap[j]){
							swap(heap, (j-1)/2, j);
							j=(j-1)/2;
						}
					} 
				}
			}
		}
		else{
			//进堆 
			if(tmp-d*(i-maxi)>heap[0]){
				heap[0]=tmp;
				maxi=i;
				int j=0, l=1, r=2;
				while(l<k){
					if(r<k&&heap[r]<heap[l]){
						if(heap[j]>heap[r]){
							swap(heap, r, j);
							j = r;l=j*2+1;r=l+1;
						}
						else break;
					}
					else{
						if(heap[j]>heap[l]){
							swap(heap, l, j);
							j = l;l=j*2+1;r=l+1;
						}
						else break;
					}
				} 
			}
		}
		for(int t=0;t<heapl;t++)cout<<heap[t]<<' ';
		cout<<endl; 
	}
	int ans=0;
	for(int f=0;f<heapl;f++)ans+=heap[f];
	ans-=(maxi+1)*d;
	return ans;
}

int main(){
	int n, m, d;
	cin>>n>>m>>d;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=maxk(a,m,n,d);
	cout<<ans;
	return 0;
}