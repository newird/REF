#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> number;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		number[i] = x;
	}

	int temp = 0, max = 0;
	for (int i = 0; i < n; i++)
	{
		temp = 0;
		for (int j = i + 1; j < n; j++)
		{
			temp = number[j] - number[i];
			max = max > temp ? max : temp;
		}
	}
	cout << max;
	return 0;
}