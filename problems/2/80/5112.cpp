#include<iostream>
#include<stack>

using namespace std;
int main()
{
	int n;
	cin>>n; 
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int helper = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (a[j] - a[i] > helper)
			{
				helper = a[j] - a[i];
			}
		}
	}
	cout << helper;
}