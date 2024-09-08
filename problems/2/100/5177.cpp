#include <stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int n, max=0,t,min=100000;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; //cout << a[i];
		t = a[i] - min;
		if (a[i] < min) min= a[i];
        if (t > max) {
				max = t;
			}

	}

	cout << max;
	return 0;
}