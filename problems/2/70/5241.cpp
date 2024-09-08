#include<iostream>
using namespace::std;
int main()
{
	int maxofone=0;
	int maxofall = 0;
	int  n;
	int p[100000]={0};
	//int pmax[100000] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	for (int i = 0; i < n - 1; i++)
	{
		while (i+1<n-1&&p[i + 1] < p[i])i++;
		for (int j = i + 1; j < n; j++)
		{
			while (j < n && p[j] <= p[i])j++;
			while (j < n && p[j] < p[j+1])j++;
			if (p[j] - p[i] > maxofall)maxofall = p[j] - p[i];


		}
	}

	cout << maxofall;


	return 0;
}