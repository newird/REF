#include<iostream>
using namespace std;

int get_max(int n, int m, int nums[], int d)
{
	int last_day = 1;
	int max = 0;
	int* max_nums = new int[m+1];
	int temp = 0;
	while (last_day <= m)
	{
		max_nums[last_day] = nums[last_day];
		if(max_nums[last_day]>0)
			temp += max_nums[last_day];
		int k = temp - d * last_day;
		if (k > max)
			max = k;

		last_day++;
	}
	while (last_day <= n)
	{
		if (nums[last_day > 0])
		{
			int min = max_nums[1];
			int min_pos = 0;
			for (int i = 1; i <= m; i++)
			{
				if (max_nums[i] <= min)
				{
					min = max_nums[i];
					min_pos = i;
				}
			}
			if (nums[last_day] > max_nums[min_pos] && max > 0)
			{
				int temp = 0;
				if (max_nums[min_pos] > 0)
					temp = max - max_nums[min_pos] + nums[last_day] - (last_day - m) * d;
				else
					temp = max + nums[last_day] - (last_day - m) * d;
				max_nums[min_pos] = nums[last_day];
				if (temp > max)
					max = temp;
			}
			else if (nums[last_day] > max_nums[min_pos])
			{
				max_nums[min_pos] = nums[last_day];
				int temp = 0;
				for (int i = 1; i <= m; i++)
				{
					if (max_nums[i] > 0)
						temp += max_nums[i];
				}
				temp -= d * last_day;
				if (temp > max)
					max = temp;
			}
		}
		last_day++;
	}
	return max;
}


int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	int* nums = new int[n + 1];
	nums[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> nums[i];
	cout << get_max(n,m,nums,d) << endl;
	return 0;
}