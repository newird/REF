#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int stack[n+1];
	int po=0,max=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]-stack[0]>max){max=arr[i]-stack[0];}
		if(po==0){stack[0]=arr[i];po++;}
		else if(arr[i]>=stack[po-1]){stack[po]=arr[i];po++;}
		else{while(arr[i]<stack[po-1]){po--;if(po==0)break;}stack[po]=arr[i];po++;}
   }
	cout<<max<<endl;
}