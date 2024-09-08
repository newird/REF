#include<iostream>
using namespace std;

int *arr=new int[200000];
int d,n;


int best(int i,int m,int gap){
	if(m==0)return 0;
	if(i==n)return 0;
	int a=arr[i]-gap*d+best(i+1,m-1,1);
	int b=best(i+1,m,gap+1);
	if(a>=b)return a;
	else return b;
}

int main(){
	int m;
	cin>>n>>m>>d;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<best(0,m,1);
}