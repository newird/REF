#include<iostream>
using namespace std;
int main()
{
	long int N;
	long long sum = 0;
	cin>>N;
	if(N<1)
		sum--;
	else{
		int i;
		for(i = 0; i <= N ; i++)
		{
			sum += i;
		}
	}
	cout<<sum;
	return 0;
}