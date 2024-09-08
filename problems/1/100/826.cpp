#include<bits/stdc++.h> 
using namespace std;


int main()
{
	long long N,sum=0;
	cin>>N;
	if(N>=1)
		sum=N*(N+1)/2; 
	else
		sum=-1;
		

	cout<<sum;

	return 0; 
}
