#include <iostream>

using namespace std;

void swap(long long a[], long long i, long long j){
	long long tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
}

long long max(long long a, long long b){
	return a>b?a:b;
}

long long maxk(long long a[], long long k, long long n, long long d){
	long long heap[k];
	long long maxi=-1;
	long long heapl=0;
	long long tmpans=0;
	long long tmpsum=0;
	for(long long i=0;i<n;i++){
		long long tmp=a[i];
		cout<<tmp<<' '<<heapl<<endl;
		if(heapl<k){
			if(tmp>0){
				heap[heapl++]=tmp;
				maxi=i;
				tmpsum += tmp;
				tmpans = max(tmpans, tmpsum-d*(maxi+1));
				//满了，调整堆 
				if(heapl==k){
					for(long long p=0;p<k;p++){
						long long j=p;
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
			if(tmp>heap[0]){
				tmpsum += tmp-heap[0];
				heap[0]=tmp;
				maxi=i;
				tmpans = max(tmpans, tmpsum-d*(maxi+1));
				long long j=0, l=1, r=2;
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
		for(long long t=0;t<heapl;t++)cout<<heap[t]<<' ';
		cout<<endl; 
	}
	return tmpans;
}

int main(){
	long long n, m, d;
	cin>>n>>m>>d;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long ans=maxk(a,m,n,d);
	cout<<ans;
	return 0;
}