#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	if(n<1)
		cout<<-1;
	else
	{
		long long int y=0;
		for(int i=1;i<=n;i++)
			y+=i;
		cout<<y;
	}
	return 0;
}