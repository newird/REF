#include <iostream>
using namespace std;

int a[100002], b[100002],result[100002];
int n, m,num,len,add_num;

int main()
{
	cin >> n >> m;
	num = add_num = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	if (n > m)
	{
		len = n;
	}
	else {
		len = m;
	}
	for (int i = 0; i < len; i++)
	{
		num = a[i] + b[i] + add_num;
		add_num = 0;
		if (num >= 10)
		{
			add_num = 1;
			num = num - 10;
		}
		result[i] = num;
	}
	if (add_num > 0)
	{
		result[len] = add_num;
		for (int i = len; i >= 0; i--)
			cout << result[i];
	}
	else {
		for (int i = len - 1; i >= 0; i--)
			cout << result[i];
	}

}