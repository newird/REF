#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	int* happiness = new int[n];
	
	for (int i = 0; i < n; ++i)
	{
		cin >> happiness[i];
		happiness[i] -= d;
		
	}
	int max_happy = 0;
	int times = 0;
	int value = 0;
	int* max_happiness = new int[m];
	int num = 0;
	int i;
	for (i = 0; i < n && times < m; ++i)
	{
		if (happiness[i] > -d)
		{
			value += happiness[i];
			++times;
		}
		else
			value += -d;
		if (happiness[i] > -d)
		{
			if (num < m)
			{
				max_happiness[num] = happiness[i];
				num++;
				if (num == m)
					sort(max_happiness, max_happiness + m);
			}
			else if (num == m)
			{
				int j;
				for (j = m - 1; j >= 0 && max_happiness[j] < happiness[i]; --j);
				if (j >= 0)
				{
					for (int k = 0; k < j; ++k)
						max_happiness[k] = max_happiness[k + 1];
					max_happiness[j] = happiness[i];
				}
			}
		}
		max_happy = (max_happy > value) ? max_happy : value;
	}
	max_happy = (max_happy > 0) ? max_happy : 0;

	if (i < n)
	{
		for (; i < n; ++i)
		{
			if (happiness[i] <= 0)
				continue;
			else
			{
				int sum_happy = happiness[i];
				for (int j = 1; j < m; ++j)
					sum_happy += max_happiness[j];
				sum_happy -= (i - m + 1) * d;
				max_happy = (max_happy > sum_happy) ? max_happy : sum_happy;
				
				int j = m - 1;
				while (max_happiness[j] > happiness[i])
					--j;
				if (j >= 0)
				{
					for (int k = 0; k < j; ++k)
						max_happiness[k] = max_happiness[k + 1];
					max_happiness[j] = happiness[i];
				}				
			}
		}
	}
	std::cout << max_happy;
	return 0;
}