#include<iostream>
using namespace::std;

int main()
{
	int n, m,max;
	//int add = 0;
	int a[10000], b[10000];
	int c[10000]={0};
	cin >> n >> m;
	//cout << "test1" << endl;
	if (n > m)max = n;
	else max = m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	//cout << "test2" << endl;
	for (int i = 0; i < max; i++)
	{
		if (a[i] + b[i] > 9)c[i + 1] = 1;
		c[i] += (a[i] + b[i]) % 10;
	}
	//cout << "test3" << endl;
	if (c[max] == 1)cout << "1";
	for (int i = max - 1; i >= 0; i--)cout << c[i];
	return 0;
}