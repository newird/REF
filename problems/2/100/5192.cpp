#include <iostream>
using namespace std;

int a[100001]={0};
int min_l[100001] = { 0 };
int n;
int main()
{
	cin >> n;
	int max_r = 0;
	cin >> a[0];
	min_l[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		cin >> a[i];
		if (a[i] - min_l[i - 1] > max_r)
		{
			max_r = a[i] - min_l[i - 1];
		}
		if (a[i] < min_l[i-1])
		{
			min_l[i] = a[i];
		}
		else {
			min_l[i] = min_l[i - 1];
		}
	}
	cout << max_r << endl;
}