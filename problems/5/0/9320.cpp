#include <iostream>
using namespace std;
void sort(int* data,int end)
{
	int temp = data[0];
	int left = 1;
	int right = end - 1;
	int middle = 0;
	while(left <= right)
	{
		middle = (left + right)/2;
		if(temp < data[middle])
		{
			right = middle-1;
		}else
		{
			left = middle + 1;
		}
	}
	memmove(&data[0],&data[1],left * sizeof(int));
	data[left] = temp;
		
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
		if(max_num[0] < num[i])
		{
			sum += num[i] - max_num[0];
			max_num[0] = num[i];
			sort(max_num,m - 2);
		}
	}
	
	if(max < 0)
	{
		max = 0;
	}
	cout << max;
	return 0;
}