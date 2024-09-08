#include <iostream>
using namespace std;

long int sum(int n, int result = 0)
{
	if (n == 0)
		return result;
	else
		return sum(n - 1, result + n);
}

int main()
{
	int n;
	cin>>n;
	if (n < 1)
		cout<<-1;
	else
		cout<<sum(n);
	return 0;
}