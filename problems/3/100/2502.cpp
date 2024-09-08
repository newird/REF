#include<iostream>
using namespace std;


int numa[100001]={0};
int numb[100001]={0};

int main()
{
	int a, b;
	int* pa;
	int* pb;
	cin >> a >> b;
	if (a < b)
	{
		swap(a, b);
		for (int i = 1; i <= b; ++i)
			cin >> numb[i];
		for (int i = 1; i <= a; ++i)
			cin >> numa[i];
	}
	else
	{
		for (int i = 1; i <= a; ++i)
			cin >> numa[i];
		for (int i = 1; i <= b; ++i)
			cin >> numb[i];
	}
	pa = numa + 1;
	pb = numb + 1;
	while (pa <= numa+a)
	{
		if (*pa + *pb >= 10)
			*(pa + 1)+=1;
		*pa = (*pa + *pb) % 10;
		pa++;
		pb++;
	}
	if (numa[a + 1] == 1)
		cout << numa[a + 1];
	for (int i = a; i > 0; --i)
	{
		cout << numa[i];
	}
}