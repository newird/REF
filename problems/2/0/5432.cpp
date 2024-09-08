#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

void FUNC(int n);


int main()
{
	int n;
	cin >> n;
	FUNC(n);
	return 0;
}

void FUNC(int n)
{
	vector <int> angka(n);
	int simpen;
	int result;
	int max=-1000000000;
	for (int i = 0; i < n; i++)
	{
		cin >> angka[i];
	}
	for (int i = 0; i < n; i = i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			result = angka[j] - angka[i];
			if (result > max)
			{
				max = result;
			}
		}
	}
	if (max <= 0)
	{
		max = 0;
	}
	cout << max;
}