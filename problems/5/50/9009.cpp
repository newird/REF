#include<iostream>
using namespace std;
static int daily_dec;
static int max_day;
static int *movie_per_day;

int maxHappy(int cur_day, int chances_left, int cur_max = 0, int last_watch_day = -1)
{
	if (cur_day == max_day) return cur_max;
	if (chances_left == 0) return cur_max;
	int if_watch = maxHappy(cur_day + 1, chances_left - 1, cur_max + movie_per_day[cur_day] - (cur_day - last_watch_day) * daily_dec, cur_day);
	int if_nwatch = maxHappy(cur_day + 1, chances_left, cur_max, last_watch_day);
	return if_watch > if_nwatch ? if_watch : if_nwatch;
}

int main()
{
	int chances;
	cin >> max_day >> chances >> daily_dec;
	movie_per_day = new int[max_day];
	for (int i = 0; i < max_day; i++)
		cin >> movie_per_day[i];
	cout << maxHappy(0, chances);
	delete[] movie_per_day;
	return 0;
}