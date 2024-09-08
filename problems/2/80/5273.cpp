#include<iostream>
using namespace std;
int main()
{
	int n,res=0,now=0,lastmax=0,max=0,start=0,lastloc=0;
	int a[100000] = { 0 }, b[100000] = {0};
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a[i] = temp;
		if (max < temp)
		{
			lastmax = max;
			max = temp;
			lastloc = i+1;
		}
		if (temp > lastmax)
			start = 0;
		else
			start = lastloc;
		for (int j = start; j <= i; j++)
		{
			if(temp>b[j])
				b[j] = temp;	
		}
	}
	for (int i = 0; i < n; i++)
	{
		now = b[i] - a[i];
		if (now > res)
			res = now;
	}
	cout << res;
	return 0;
}