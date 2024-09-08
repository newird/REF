#include <iostream>
using namespace std;
void quick_sort(int* data,int start,int end)
{
	if(start >= end)
	{
		return;
	}
	
	int judge_1 = 0;
	int judge_2 = 1;
	for(int i = start + 1;i <= end;i++)
	{
		if(data[i] < data[i - 1])
		{
			judge_1 = 1;
		}else if(data[i] > data[i - 1])
		{
			judge_2 = 0;
		}
		if(judge_1 == 1 && judge_2 == 0)
		{
			break;
		}
	}
	if(judge_1 == 0)
	{
		return;
	}
	if(judge_2 == 1)
	{
		for(int i = 0;i <= (end - start)/2;i++)
		{
			swap(data[start + i],data[end - i]);
		}
		return;
	}
	int base = data[start];
	int i = start;
	int j = end;
	int p = i + 1;

	while(p <= j)
	{
		if(data[p] > base)
		{
			swap(data[p],data[j]);
			j--;
		}else if(data[p] < base)
		{
			swap(data[i],data[p]);
			i++;
			p++;
		}else
		{
			p++;
		}
	}
	
	quick_sort(data,j + 1,end);
	quick_sort(data,start,i - 1);
	
	return;
}
int main()
{
	int n,m,d;
	cin >> n >> m >> d;
	int num[n]{};
	for(int i = 1;i <= n;i++)
	{
		cin >> num[i];
	}

	int max_num[m - 1]{};
	int max = 0;
	int sum = 0; 
	for(int i = 1;i <= n;i++)
	{
		if(sum + num[i] - i * d > max)
		{
			max = sum + num[i] - i * d;
		}
		
		if(i <= m - 1 && num[i] > 0)
		{
			max_num[m - 2 - i] = num[i];
			sum += num[i];
			if(i == m - 1)
			{
				quick_sort(max_num,0,m - 2);
			}
		}else if(max_num[0] < num[i])
		{
			sum += num[i] - max_num[0];
			max_num[0] = num[i];
			quick_sort(max_num,0,m - 2);
		}

	}
	
	if(max < 0)
	{
		max = 0;
	}
	cout << max;
	return 0;
}