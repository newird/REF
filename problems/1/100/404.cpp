#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n<1)cout<<-1;
	if(n>=1){
	long long  sum=0;
	for(int i=1;i<=n;i++){
		sum+=i;
	}
		cout<<sum;}
	return 0;
}

