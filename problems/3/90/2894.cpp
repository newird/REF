#include <iostream>
using namespace std;
#include <stdio.h>

void FUNCT(int n, int m);

int main()
{
	int n, m;
	cin >> n >> m;
	FUNCT(n, m);
	return 0;
}

void FUNCT(int n, int m)
{
	long long a[100000] = {0};
	long long b[100000] = {0};
	long long c[100000] = {0};
	int big = max(n, m);  // 使用max函数

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	int carry = 0;
	for (int i = 0; i < big; i++)
	{
		int temp = a[i] + b[i] + carry;
		c[i] = temp % 10;
		carry = temp / 10;
	}
	while (carry)
	{
		c[big] = carry % 10;
		carry /= 10;
		big++;
	}

	bool flag = false;
	for (int i = big - 1; i >= 0; i--)
	{
		if(c[i] != 0) flag = true;
		if(flag)
			cout << c[i];
	}
	if(!flag) cout << "0";  // 处理0的情况
	cout << endl;
}
