#include<iostream>
using namespace std;

int *arr=new int[200000];
int d,n;


int best(int i,int m,int gap,int sum){
	if(m==0)return sum;
	if(i==n)return sum;
	int a=best(i+1,m-1,1,sum+arr[i]-gap*d);
	int b=best(i+1,m,gap+1,sum);
	if(a>=b)return a;
	else return b;
}

int main(){
	int m;
	cin>>n>>m>>d;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<best(0,m,1,0);
}