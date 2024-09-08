#include<iostream>
using namespace std;
int main()
{
	int n,res=0,now=0,mymax=0;
	int a[100000] = { 0 }, b[100000] = {0};
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a[i] = temp;
		for (int j = 0; j <= i; j++)
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