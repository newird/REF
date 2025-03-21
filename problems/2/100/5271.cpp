#include<iostream>
using namespace std;

int get_max(int *p,int start,int n)
{
	int res = 0;
	int i = start;
	int max = 0;
	while (i < n)
	{
		if (p[i] >= max)
		{
			max = p[i];
			res = i;
		}
		i++;
	}
	return res;
}

int get_min(int* p,int start ,int maxloc)
{
	int i = start;
	int min = 10000000;
	while (i < maxloc)
	{
		if (min >= p[i])
			min = p[i];
		i++;
	}
	return min;
}
int main()
{
	int n;
	cin >> n;
	int* p = new int[n];
	int i = 0;
	
	while (i < n)
	{
		cin >> p[i];
		i++;
	}
	int maxloc = -1;
	int res = 0;
	while (maxloc != n - 1)
	{
		int max = maxloc;
		maxloc = get_max(p, maxloc + 1, n);
		int min = get_min(p, max + 1, maxloc);
		if (res <= p[maxloc] - min)
			res = p[maxloc] - min;
	}
	if (maxloc == 0)
		cout << 0;
	else if (res==0)
		cout << 0;
	else
		cout << res;
	return 0;
}