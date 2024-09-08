#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long sum;
int main()
{
	cin>>n;
	if(n<1) 
	{
		cout<<"-1\n";
	}
	else {
		sum=0;
		for(int i=1;i<=n;i++)
			sum+=i;
		cout<<sum<<"\n";
	}
	
	
	return 0;
}