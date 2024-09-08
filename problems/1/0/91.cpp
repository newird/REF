#include <iostream>
using namespace std;
int main()
{
	int n,result=0;
	cin>>n;
	if(n<1)
	{
	result=-1;
	cout <<result;
	return 0;
}
	
	for(int i=1;i<=n;i++)
	{
		result+=i;
	}
	cout <<result;
	return 0;
}