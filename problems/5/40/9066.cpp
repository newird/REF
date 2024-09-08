#include<iostream>
using namespace std;

int get_max(int last_day,int m,int nums[],int d)
{
	int* max_nums = new int[m];
	int max_pos = 1;
	
	for (int i = 0; i <m-1;i++)
	{
		int max = -100000000;
		for (int j = 1; j < last_day; j++)
		{
			if (nums[j] > max)
			{
				max = nums[j];
				max_pos = j;
			}
		}
		max_nums[i] = nums[max_pos];
		nums[max_pos] = -100000000;
	}
	int res = 0;
	max_nums[m - 1] = nums[last_day];
	for (int i = 0; i < m; i++)
	{
		if (max_nums[i] > 0)
			res += max_nums[i];
	}

	return res-d*last_day;
}


int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	int* nums = new int[n + 1];
	nums[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> nums[i];
	int last_day = n;
	int max = 0;
	for (last_day = n; last_day > 0; last_day--)
	{
		int k = get_max(last_day, m, nums, d);
		if (k > max)
			max = k;
	}

	cout << max << endl;
	return 0;
}