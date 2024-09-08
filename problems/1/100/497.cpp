using namespace std;
#include<iostream>
int main()
{
	long long n;
	cin>>n;
	if (n < 1)
		printf("-1");
	else
	{
		long long m =(n* (1 + n) )/ 2;
		cout<<m;
	}
	return 0;
}
