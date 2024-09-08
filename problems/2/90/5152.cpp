#include<iostream>
using namespace std;

int main()
{
	int n;
	int index = 0;
	int price[100000];
	int min = 10001;
	int max = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> price[i];
	}
	for (int i = 0; i < n; ++i) // find the minimum among all
	{
		if (price[i] < min)
		{
			min = price[i];
			index = i;
		}
	}
	for (int j = index + 1; j < n; ++j)
	{
		int curr = price[j] - price[index];
		if (curr > max)
		{
			max = curr;
		}
	}
	cout << max;
	return 0;
}