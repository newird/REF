
#include <iostream>
#include<math.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int sum1 = 0;
	int sum2 = 0;
	
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		sum1 = sum1 + pow(10, i)*x;
		
		
	}
	for (int i = 0; i < m; ++i)
	{

		int x;
		cin >> x;
		sum2 = sum2 + pow(10, i)*x;

	}
	
	cout << sum1 + sum2;
	return 0;
}