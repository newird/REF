#include<iostream>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long sum=0;
	if(n<1)
		cout<<-1;
	else
	{
		for(int i=1;i<=n;i++)
			sum+=i;
		cout<<sum;
			}
	
	return 0;
}