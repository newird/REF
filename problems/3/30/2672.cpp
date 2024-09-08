#include<iostream>
using namespace std;

int GetNumber(int arr[], int digit)
{
	int sum = 0;
	for (int i = digit - 1; i >= 0; --i)
	{
		int j = i;
		int temp = 1;
		while (j > 0)
		{
			temp = temp * 10;
			j = j - 1;
		}
		sum = sum + (arr[i] * temp);
	}
	return sum;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int arr1[100000];
	int arr2[100000];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr1[i];
	}
	for (int j = 0; j < m; ++j)
	{
		cin >> arr2[j];
	}
	int ans1 = GetNumber(arr1, n);
	int ans2 = GetNumber(arr2, m);
	int ans = ans1 + ans2;
	cout << ans;
	return 0;
}