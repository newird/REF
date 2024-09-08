#include<iostream>
using namespace std;
int main()
{
	long long int n, i, j, k = 0, s;
	cin >> n;
	int p[100010];
	for (i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	for (j = 0; j < n - 1; j++)
	{
		for (s = j + 1; s < n; s++)
		{
			if ((p[s] - p[j])>k)
			{
				k = p[s]-p[j];
			}
		}
	}
	cout << k;
}
