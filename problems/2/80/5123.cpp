#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* p = new int[n];
	for (int i = 0; i != n; i++)
		cin >> p[i];
	int max = 0;
	for (int i = 0; i != n - 1; i++)
		for (int j = i + 1; j != n; j++)
			max = (max > p[j] - p[i]) ? max : (p[j] - p[i]);
	cout << max;
}