#include<iostream>
using namespace std;

int main()
{	
	int n, m;
	cin >> n >> m;
	int num_n[n], num_m[m];
	for(int i = 0; i < n; i++)
	{
		cin >> num_n[i];	
	}
	for(int i = 0; i < m; i++)
	{
		cin >> num_m[i];	
	}
	int max = 1 + (n > m) ? n : m;
	int res[max];
	res[0] = num_n[0] + num_m[0];
	for(int i = 1; i< max + 1; i++)
	{
		res[i] = num_n[i] + num_m[i] + (num_n[i - 1] + num_m[i - 1]) % 10;
	}
	for(int i = max; i >= 0; i--)
	{
		if(i < max || res[i] != 0)
			cout << res[i];	
	}
	return 0;
	
}