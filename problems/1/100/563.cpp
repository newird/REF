#include <iostream>

using namespace std;

int main()
{
	
	long long int N;
	
	cin >> N;
	
	if (N > 1||N==1)
	{
		
		long long int sum = N * (N + 1) / 2;
		
		cout << sum << endl;
	}
	
	else
	{
		cout << -1 << endl;
	}
	
	return 0;
}