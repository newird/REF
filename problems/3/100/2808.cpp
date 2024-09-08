#include<bits/stdc++.h> 
using namespace std;

int main()
{
	int len1, len2,max;//数字长度 
	cin>>len1>>len2; 
	if(len1>len2) max=len1;
	else max=len2;
	int a[max]={0};
	int b[max]={0};
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
		a[i]= a[i]+b[i] + up;
		if (a[i]>=10){
		up=1; 
		}else{
			up=0;
		}
		a[i] %= 10;
	}
		if (up ==1)//考虑最高位进位的情况
	{
		a[max] = 1;
			for (int i = max; i >= 0; i--)
		{
			cout << a[i];//倒序输出 
		}
	}
		else
	{
			for (int i = max-1; i >= 0; i--)
		{
			cout << a[i];//倒序输出 
		}
	}
	return 0;
}
/*
2 3
5 5
5 5 5
*/