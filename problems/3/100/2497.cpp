#include <iostream>

using namespace std;

void add(int n, int m, int a[], int b[]){
	int c[n+1];
	int carry=0;
	for(int i=0;i<n;i++){
		if(i<m){
			int tmp=a[i]+b[i]+carry;
			carry=tmp/10;
			c[n-i]=tmp%10;
		}
		else{
			int tmp=a[i]+carry;
			carry=tmp/10;
			c[n-i]=tmp%10;
		}
	}
	c[0]=carry;
	if(c[0]){
		cout<<c[0];
	}
	for(int i=1;i<n+1;i++){
			cout<<c[i];
		}
}

int main(){
	int n,m;
	cin>>n>>m;
	int a[n], b[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	if(n>m){
		add(n,m,a,b);
	}
	else{
		add(m,n,b,a);
	}
	return 0;
}