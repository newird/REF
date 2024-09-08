#include<iostream>
using namespace std;
void Plus(int a[], int b[],int max);
int main()
{
	int m, n;
	int a[100001]= { 0 };
	int b[100001] = { 0 };
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	if (m >= n)
		Plus(a, b,m);
	else
		Plus(b, a,n);
}
void Plus(int a[], int b[],int max)
{
	for (int loc = 0; loc <max; loc++)
	{
		a[loc] = a[loc] + b[loc];
		if (a[loc] >= 10)
		{
			a[loc] -= 10;
			a[loc + 1] += 1;
		}
	}
	if (a[max] != 0)
		cout << a[max];
	for (int x = (max-1); x >=0; x--)
		cout << a[x];
	
}