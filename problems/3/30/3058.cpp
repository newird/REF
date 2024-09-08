#include <iostream>
using namespace std;

int pow10(int x)
{
	int res = 1;
	for (int i = 0; i < x; i++)
	{
		res =res*10;
	}
	return res;
}

int main()
{
	int a=0;
	int b=0;
	int sizea;
	int sizeb;
	int res=0;
	int iadder;
	cin >> sizea >> sizeb;
	for (int i = 0; i < sizea; i++)
	{
		cin >> iadder;
		a += iadder*pow10(i);
	}
	for (int i = 0; i < sizeb; i++)
	{
		cin >> iadder;
		b += iadder*pow10(i);
	}
	res = a+b;
	cout << res;
	return 0;
}