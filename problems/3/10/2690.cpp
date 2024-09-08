#include<iostream>
using namespace std;

int main()
{
	long len1, len2;
	cin >> len1 >> len2;
	const long MaxSize = (len1 > len2 ? len1 : len2) + 1;
	int* num1 = new int[MaxSize];
	int* num2 = new int[MaxSize];
	int* numadd = new int[MaxSize];
	int i = 0;
	while (i < MaxSize)
	{
		if (i < len1)
			cin >> num1[i];
		else
			num1[i] = 0;
		i++;
	}
	i = 0;
	while (i < MaxSize)
	{
		if (i < len2)
			cin >> num2[i];
		else
			num2[i] = 0;
		i++;
	}
	int carry=0;
	i = 0;
	while (i < MaxSize)
	{
		int p = num1[i] + num2[i];
		numadd[i] = p % 10 + carry;
		carry = p / 10;
		i++;
	}
	i = 0;
	if (numadd[MaxSize-1] == 1)
		while (i < MaxSize)
		{
			cout << numadd[MaxSize - i - 1];
			i++;
		}
	else
		while(i < MaxSize-1)
		{
			cout << numadd[MaxSize - i - 2];
			i++;
		}

	return 0;
}