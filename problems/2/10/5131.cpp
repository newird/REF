#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* p = new int[n];
	int i = 0;
	while (i < n)
	{
		cin >> p[i];
		i++;
	}
	int money = 0;
	int res = 0;
	i = 0;
	while (i < n - 1)
	{
		int j = i + 1;
		while (j < n)
		{
			money = p[i] - p[j];
			if (money >= res)
				res = money;
			j++;
		}
		i++;
	}
	if (res <= 0)
		cout << 0;
	else
		cout << res;

	return 0;
}