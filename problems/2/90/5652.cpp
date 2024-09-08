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
	int kecil = 10000, besar = -kecil;
	int angka[100000];
	int simpen, result;

	for (int i = 0; i < n; i++)
	{
		cin >> angka[i];
		if (kecil > angka[i])
		{
			kecil = angka[i];
			simpen = i;
		}
	}
	if (simpen == n - 1)
	{
		result = 0; 
		for (int i = 0; i < n; i++)
		{
			cin >> angka[i];
			if (kecil > angka[i])
			{
				kecil = angka[i];
				simpen = i;
			}
		}
		if (simpen == n - 1)
		{
			result = 0;
			for (int i = 0; i < n; i++)
			{
				cin >> angka[i];
				if (kecil > angka[i])
				{
					kecil = angka[i];
					simpen = i;
				}
			}
			for (int i = simpen + 1; i < n; i++)
			{
				besar = max(besar, angka[i]);
			}
			result = besar - kecil;
		}
		for (int i = simpen + 1; i < n; i++)
		{
			besar = max(besar, angka[i]);
		}
		result = besar - kecil;
	}
	else
	{
		for (int i = simpen + 1; i < n; i++)
		{
			besar = max(besar, angka[i]);
		}
		result = besar - kecil;
	}

	cout << result;
}