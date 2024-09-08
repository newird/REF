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
		int pr = 0;
		for (int j = i + 1; j < n; ++j)
		{
			if (p[j] > p[i])
				pr = (pr > p[j] - p[i]) ? pr : (p[j] - p[i]);
		}
		max_p = (max_p > pr) ? max_p : pr;
	}
	cout << max_p;
	return 0;
}