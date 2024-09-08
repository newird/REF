#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* p = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	int d = 0;
	int k = p[0];
	for (int i = 0; i < n; i++)
	{
		if (p[i] > k)
		{
			d = d > (p[i] - k) ? d : (p[i] - k);
		}
		k = k < p[i] ? k : p[i];
	}cout << d << endl;
}
