#include <iostream>
#include <string>
using namespace std;

int main()
{
	int len1, len2;//数字长度 
	cin>>len1>>len2; 
	int *a=new int[len1];
	int *b=new int[len2];
	
	for (int k = 0; k<len1;k++)//逆序存放
	{
		cin>>a[k];
	}

	for (int k = 0; k<len2;k++)
	{
		cin>>b[k];
	}
	
	int up = 0, max = len1 >= len2 ? len1 : len2;
	
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
	return 0;
}


