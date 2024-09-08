#include <iostream>
using namespace std;

int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	int* happiness = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> happiness[i];
		happiness[i] -= d;
	}
	int max_happy = 0;
	int times = 0;
	int value = 0;
	for (int i = 0; i < n && times <= m; ++i)
	{
		if (happiness[i] > -d)
		{
			value += happiness[i];
			++times;
		}
		else
			value += -d;

		max_happy = (max_happy > value) ? max_happy : value;
	}
	max_happy = (max_happy > 0) ? max_happy : 0;
	cout << max_happy;
	return 0;
}