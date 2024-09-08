
#include<iostream>
using namespace::std;

int main()
{
	int n, m;
	int max;
	//int add = 0;
	short sum = 0;
	short a1[100000] = { 0 };
	short b1[100000] = { 0 };
	short c1[100000] = { 0 };
	cin >> n >> m;
	//cout << "test1" << endl;
	if (n > m)max = n;
	else max = m;
	for (int i = 0; i < n; i++)
		cin >> a1[i];
	for (int i = 0; i < m; i++)
		cin >> b1[i];
	//cout << "test2" << endl;
	for (int i = 0; i < max; i++)
	{
		sum = sum + a1[i] + b1[i];
		if (a1[i] + b1[i] > 9)c1[i + 1] = 1;
		c1[i] =c1[i]+(a1[i] + b1[i] + 10) % 10;
	}
	//cout << "test3" << endl;
	if (sum == 0)cout << "0";
	else {
	if (c1[max] == 1)cout << "1";
	for (int i = max - 1; i >= 0; i--)cout << c1[i];
}
	return 0;
}