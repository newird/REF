#include<iostream>
using namespace std;

int main(){
	int n,m,d,num,am=0；
	long long max=0,sum=0;
	cin>>n>>m>>d;
	int arr[m];
	for(int i=1;i<n+1;i++){
		cin>>num;
		if(num<=0)continue;
		if(am>=m){
			if(num<arr[0])continue;
			else{
				sum-=arr[0];
				sum+=num;
				arr[0]=num;
				int way=0;
			while (2 * way + 2 < am && (arr[way] > arr[2 * way + 1] || arr[way] > arr[2 * way + 2])) { 
				int v=arr[way];
			   if (arr[2 * way + 2] > arr[2 * way + 1]) { 
				   arr[way] = arr[2 * way + 1]; way = 2 * way + 1; arr[way] = v; } 
			   else {arr[way] = arr[2 * way + 2]; way = 2 * way + 2; arr[way] = v; }
			}
			if (2 * way + 1 < am) { if (arr[way] > arr[2 * way + 1]) {  
				int v=arr[way]; arr[way] = arr[2 * way + 1]; way = 2 * way + 1; arr[way] = v; } 
			}
			}
		}
		else{
			sum+=num;
			arr[am]=num;
			int way=am;
			while(way!=0&&arr[(way-1)/2]>arr[way]){int v=arr[way];arr[way]=arr[(way-1)/2];way=(way-1)/2;arr[way]=v;}
			am++;
		}
		
	}
   cout<<max;
}