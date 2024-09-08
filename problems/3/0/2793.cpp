#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a[100],b[100];

	string A, B;
	cin >> A >> B;

	int len1, len2;//数字长度 
	len1 = A.length();
	len2 = B.length();
	
	for (int i = len1 - 1, k = 0; i != -1; i--,k++)//逆序存放
	{
		a[k] = A[i] - '0';//字符转化为数字 
	}

	for (int i = len2 - 1, k = 0; i != -1; i--,k++)
	{
		b[k] = B[i] - '0';
	}
	
	int up = 0, max = len1 >= len2 ? len1 : len2;//进位、和的长度 
	
	for (int i = 0; i < max; i++)//加法
	{
		a[i] += b[i] + up;
		up = a[i] / 10;//进位 
		a[i] %= 10;
		//最终up=0表示无最高位进位 
	}
	if (up > 0)//考虑最高位进位的情况
	{
		a[max] += up;
		max += 1;//长度加1
	}

	for (int i = max-1; i >= 0; i--)
	{
		cout << a[i];//倒序输出 
	}
	cout <<endl;
	return 0;
}

