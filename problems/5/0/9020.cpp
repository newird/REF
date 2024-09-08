#include<iostream>
using namespace std;

int main(){
	int n,m,d,a,am=0;
	cin>>n>>m>>d;
	int arr[m+1];
	for(int i=0;i<n;i++){
		cin>>a;
		a-=(i+1)*d;
		if(am>=m){
			if(a<=arr[0])continue;
			arr[0]=a;
			int way=0;
			while ( 2 * way + 2 < am&& (a > arr[2 * way + 1] || a > arr[2 * way + 2])) { if (arr[2 * way + 2] > arr[2 * way + 1]) { if (arr[way] > arr[2 * way + 1]) { arr[way] = arr[2 * way + 1]; way = 2 * way + 1; arr[way] = a; } }
				else { if (arr[way] > arr[2 * way + 2]) { arr[way] = arr[2 * way + 2]; way = 2 * way + 2; arr[way] = a; } }
				}
				if (2 * way + 1 < am) { if (arr[way] > arr[2 * way + 1]) { arr[way] = arr[2 * way + 1]; way = 2 * way + 1; arr[way] = a; } }
		}
		else{
			arr[am] = a;
			int way = am;
			while (way>=1&&arr[(way - 1) / 2] > arr[way]) { arr[way] = arr[(way - 1) / 2]; way = (way - 1) / 2; arr[way] = a; }
			am++;
		}
	}
	int sum=0,max=-500000;
	for(int i=m-1;i>=0;i--){sum+=arr[i];if(sum>max){max=sum;}}
	cout<<max;
}