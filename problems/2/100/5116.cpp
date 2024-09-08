#include <iostream>

using namespace std;

int profit(int a[], int t){
	if(t==1)return 0;
	int min=a[0];
	int profit=0;
	for(int i=0;i<t;i++){
		if(a[i]>min)profit=profit>(a[i]-min)?profit:(a[i]-min);
		min=min>a[i]?a[i]:min;
	}
	return profit;
}


int main(){
	int t;
	cin>>t;
	int a[t];
	for(int i=0;i<t;i++){
		cin>>a[i];
	}
	int p = profit(a, t);
	cout<<p;
	return 0;
}
