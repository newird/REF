#include <vector>
#include <iostream>
#include<math.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int sum1 = 0;
	int sum2 = 0;
	int* s0 = new int[n];
	int* s1 = new int[m];
	for (int i = 0; i < n; ++i)
	{
		
		cin >> s0[i];
		
	}
	for (int i = 0; i < m; ++i)
	{

		cin >> s1[i];

	}
	for (int i = n-1; i >=0; --i)
	{

		sum1 = sum1 * 10 + s0[i];

	}
	for (int i = m - 1; i >= 0; --i)
	{

		sum2 = sum2 * 10 + s1[i];

	}
	cout << sum1 + sum2;
	return 0;
}
