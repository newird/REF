#include <iostream>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int max_happiness(int* p, int m, int d, int i, int l, int n)
{
	if (i == n || m == 0)return 0;
	
	int happiness1, happiness2;
	if (l == i - 1 && l != -1) happiness1 = max_happiness(p, m - 1, d, i + 1, i, n) + p[i];
	else happiness1 = max_happiness(p, m - 1, d, i + 1, i, n) - d * (i - l) + p[i];
	
	happiness2 = max_happiness(p, m, d, i + 1,l,n);

	return max(happiness1, happiness2);
	
}

int main()
{
	int n, m, d;
	cin >> n >> m >> d;

	int* p;
	p = new int[n];
	for (int i = 0; i < n; i++)cin >> p[i];

	cout << endl << max_happiness(p, m, d, 0, -1,n);

	delete[]p;
	return 0;
}
