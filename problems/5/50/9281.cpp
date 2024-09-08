#include <iostream>
using namespace std;

int n, m, d;

int arr[200001];
int m1[200001];
int res[200001];

int main()
{
	cin >> n >> m >> d;
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	int min_m = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] < min_m)
		{
			res[i] = res[i - 1];
		}
		else {
			for (int j = 1; j <= n; j++)
			{
				if (m1[j] == min_m)
				{
					m1[j] = arr[i];
					res[i] = res[i - 1] - min_m + arr[i];
					min_m = 100000001;
					break;
				}
			}
			for (int j = 1; j <= n; j++)
			{
				if (m1[j] <= min_m)
				{
					min_m = m1[j];
				}
			}
		}
	}

	int max_1 = 0;
	for (int i = 1; i <= n; i++)
	{
		res[i] -= i * d;
		if (res[i] > max_1)
		{
			max_1 = res[i];
		}
	}
	cout << max_1 << endl;
}