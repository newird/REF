#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	long long int n,i,j,k=0,s,e;
	int*p=new int[n];
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	for (j = 0; j < n-1; j++)
	{
		for (s = j+1; s < n; s++)
		{
			if (p[s] > p[j])
			{
				e = p[s] - p[j];
				if (e > k)
					k = e;
			}
		}
	}
	cout << k;
}