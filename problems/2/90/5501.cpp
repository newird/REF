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
	int min = 1000000000, max = -min;
	vector <int> angka(n);
	int simpen, result;

	for (int i = 0; i < n; i++)
	{
		cin >> angka[i];
		if (min > angka[i])
		{
			min = angka[i];
			simpen = i;
		}
	}
	if (simpen == n - 1)
	{
		result = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (min > angka[i])
			{
				min = angka[i];
				simpen = i;
			}
		}
		for (int i = simpen + 1; i < n; i++)
		{
			if (max < angka[i])
			{
				max = angka[i];
			}
		}
		result = max - min;
		if (result <= 0)
		{
			result = 0;
		}
	}
	else
	{
		for (int i = simpen + 1; i < n; i++)
		{
			if (max < angka[i])
			{
				max = angka[i];
			}
		}
		result = max - min;
	}
	
	cout << result;
}