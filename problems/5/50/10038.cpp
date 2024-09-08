#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int n, int nums[])
{
	for (int i = n - 1; i > 1; i--)
	{
		for (int j = n - 1; j > 1; j--)
		{
			if (nums[j] > nums[j - 1])
			{
				swap(&nums[j], &nums[j - 1]);
			}

		}
	}
}

int get_max(int n, int m, int nums[], int d)
{
	int last_day = 1;
	int max = 0;
	int* max_nums = new int[m+1];
	int temp = 0;
	while (last_day <= m)
	{
		max_nums[last_day] = nums[last_day];
		temp += max_nums[last_day];
		int k = temp - d * last_day;
		if (k > max)
			max = k;

		last_day++;
	}
	
	while (last_day <= n)
	{
		
		int temp = 0;
		for (int i = 1; i < m; i++)
			temp += nums[i];
		temp += nums[last_day];
		temp -= last_day * d;
		if (temp > max)
		{
			max = temp;
			nums[m] = nums[last_day];
			sort(m + 1, nums);
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
	{
		cin >> nums[i];
		if (nums[i] < 0)
			nums[i] = 0;
	}
	cout << get_max(n,m,nums,d) << endl;
	return 0;
}