#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* p = new int[n];
	int max_p = 0;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
	}
	for (int i = 0; i < n; ++i)
	{
		int flag = 0;
		int pr = 0;
		int j = i + 1;
		for (; j < n; ++j)
		{
			if (p[j] > p[i])
				pr = (pr > p[j] - p[i]) ? pr : (p[j] - p[i]);
			if (p[j] < p[i] && flag == 0)
			{
				flag = j;
			}
		}
		max_p = (max_p > pr) ? max_p : pr;
		if (flag != 0)
			i = flag - 1;
	}
	cout << max_p;
	return 0;
}