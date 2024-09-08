#include <iostream>
using namespace std;

int a[100001]={0};
int n;
int main()
{
	cin >> n;
	for (int i = 0; i <n; i++)
	{
		cin >> a[i];
	}
	int max_1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] - a[i] > max_1)
			{
				max_1 = a[j] - a[i];
			}
		}
	}
	cout << max_1 << endl;
}