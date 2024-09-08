#include<iostream>
using namespace std;

int get_max(int last_day,int m,int nums[],int d)
{

	int* max_nums = new int[m];
	int max_pos = 1;
	int res = 0;
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
		if (nums[max_pos] < 0)
			break;
		res += nums[max_pos];
		nums[max_pos] = -100000000;
	}
	res += nums[last_day];
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