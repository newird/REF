#include <iostream>
using namespace std;

void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
int Split(int a[], int first, int last)
{
    int split_point = rand() % (last - first + 1) + first;
    Swap(a[split_point], a[first]);
    int pivot = a[first];
    split_point = first;
    for (int i = first + 1; i <= last; ++i)
        if (a[i] < pivot)
        {
            ++split_point;
            Swap(a[i], a[split_point]);
        }
    a[first] = a[split_point];
    a[split_point] = pivot;

    return split_point;
}

void quickSort(int a[], int first, int last)
{
    if (first < last)
    {
        int split_point = Split(a, first, last); //寻找分割点
        quickSort(a, first, split_point - 1);//对分割点以左的部分进行排序
        quickSort(a, split_point + 1, last);//对分割点以右的部分进行排序
    }
}
int main()
{
	int n, m;
	long long d;
	cin >> n >> m >> d;
	long long* happiness = new long long[n];
	
	for (int i = 0; i < n; ++i)
	{
		cin >> happiness[i];
		happiness[i] -= d;
		
	}
	long long max_happy = 0;
	int times = 0;
	long long value = 0;
	long long* max_happiness = new long long[m];
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
					quickSort(max_happiness, 0, m - 1);
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
				long long sum_happy = happiness[i];
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