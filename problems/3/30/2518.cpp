#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int A[n];
	int B[m];
	
	for(int i = 0;i < n;i++)
	{
		cin >> A[i];
	}	
	
	int pre = 0;
	
	for(int i = 0;i < m;i++)
	{
		cin >> B[i];
	}	
	
	int max = (n > m) ? n : m;
	int res[max + 1] = {};
	int a;
	int b;
	
	for(int i = 0;i < max;i++)
	{
		a = 0;
		b = 0;
		if(i+1 <= n)
		{
			a = A[i];
		}
		
		if(i+1 <= m)
		{
			b = B[i];
		}
		
		if(a + b + pre >= 10)
		{
			res[i] = a + b + pre - 10;
			pre = 1;
		}else
		{
			res[i] = a + b;
			pre = 0;
		}
	}
	
	if(pre == 1)
	{
		cout << 1;
	}
	
	for(int i = max - 1;i >= 0;--i)
	{
		cout << res[i];
	}
	cout << endl;
	return 0;
}