#include <stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int n, max=0,t;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; //cout << a[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int k = n - 1; k > i; k--)
		{
			 t= a[k] - a[i];
			//cout << t;
			if (t > max){
				max = t; 
			}
		}
	}
	cout << max;
	return 0;
}