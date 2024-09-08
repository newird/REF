#include<bits/stdc++.h> 
using namespace std;

int main()
{
	int len1, len2,max;//数字长度 
	cin>>len1>>len2; 
	if(len1>len2) max=len1;
	else max=len2;
	int *a=new int[max];
	int *b=new int[len2];
	for (int i= 0;i<len1;i++)//逆序存放
	{
		cin>>a[i];
	}
	for (int i= 0;i<len2;i++)
	{
		cin>>b[i];
	}
	int up = 0;	
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

