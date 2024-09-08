#define INT_MIN     (-2147483647 - 1)
#include<iostream>
using namespace std;
static int daily_dec;
static int max_day;
static int *movie_per_day;

void siftDown(int* arr, int end, int start = 0)
{
	int i = start, j = 2 * i + 1;
	int temp = arr[i];
	while (j <= end)
	{
		if (j<end && arr[j]>arr[j + 1])j++;
		if (temp <= arr[j])break;
		else
		{
			arr[i] = arr[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	arr[i] = temp;
}

//void minHeap(int* arr, int size, int start = 0)
//{
//	int currentPos = start + size / 2 - 1;
//	for (; currentPos >= 0; currentPos--)
//		siftDown(arr, currentPos, start + size - 1);
//}

int maxHappy(int chances)
{
	int cur = 0, chances_left = chances - 1, cur_max = 0, max = 0;
	int* my_heap;
	if (chances_left == 0) my_heap = NULL;
	else my_heap = new int[chances_left] {INT_MIN};
	//最后一次看电影是在第cur天（0开始）时幸福的最大值
	for (; cur < max_day; cur++)
	{
		if (cur > 0)cur_max -= movie_per_day[cur - 1];
		cur_max += (movie_per_day[cur] - daily_dec);
		if (chances != 1)
		{
			//chances花完之前，有正则加
			if (chances_left > 0 && cur >= 1 && movie_per_day[cur - 1] > 0)
			{
				cur_max += movie_per_day[cur - 1];
				chances_left--;
				my_heap[0] = movie_per_day[cur - 1];
				siftDown(my_heap, chances - 2);
			}
			//chances花完之后，如果新的数据大于minHeap顶，入堆，加值
			else if (chances_left == 0 && cur >= 1 && movie_per_day[cur - 1] > my_heap[0])
			{
				cur_max += (movie_per_day[cur - 1] - my_heap[0]);
				my_heap[0] = movie_per_day[cur - 1];
				siftDown(my_heap, chances - 2);
			}
		}
		//更新max
		max = max >= cur_max ? max : cur_max;
	}
	delete[] my_heap;
	return max;
}

//int maxHappy(int cur_day, int chances_left, int cur_max = 0, int last_watch_day = -1)
//{
//	if (cur_day == max_day) return cur_max;
//	if (chances_left == 0) return cur_max;
//	int if_watch = maxHappy(cur_day + 1, chances_left - 1, cur_max + movie_per_day[cur_day] - (cur_day - last_watch_day) * daily_dec, cur_day);
//	int if_nwatch = maxHappy(cur_day + 1, chances_left, cur_max, last_watch_day);
//	return if_watch > if_nwatch ? if_watch : if_nwatch;
//}

int main()
{
	int chances;
	cin >> max_day >> chances >> daily_dec;
	movie_per_day = new int[max_day];
	for (int i = 0; i < max_day; i++)
		cin >> movie_per_day[i];
	cout << maxHappy(chances);
	delete[] movie_per_day;
	return 0;
}