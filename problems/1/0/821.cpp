#include<bits/stdc++.h> 
using namespace std;


int main()
{
	int N,sum=0;
	cin>>N;

	sum=abs(1-N+1)*(N+1)/2; 
	if(sum>0){
		cout<<sum;
	}	
	else{
		cout<<-1;
	}
	return 0; 
}
