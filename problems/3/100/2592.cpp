#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int max_n, min_n;
	max_n = (n > m) ? n : m;
	min_n = m + n - max_n;
	int* ret = new int[max_n + 1];
	int* add1 = new int[max_n+1]{0};
	int* add2 = new int[max_n+1]{0};
	for (int i = 0; i < n; ++i)
	{
		cin >> add1[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> add2[i];
	}
	
	int in = 0;   //进位
	for (int i = 0; i <= max_n; ++i)
	{
		ret[i] = add1[i] + add2[i] + in;
		if (ret[i] >= 10)
		{
			ret[i] %= 10;
			in = 1;
		}
		else
			in = 0;
	}
	if (ret[max_n] != 0)
		cout << ret[max_n];
	for (int i = max_n - 1; i >= 0; --i)
	{
		cout << ret[i];
	}
	return 0;
}