#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int length = m > n ? m : n;
	int* p;
	p = new int[length];
	int* q;
	q = new int[length];

	for (int i = 0; i < length; i++) {
		if (i < n)cin >> p[i];
		else p[i] = 0;
	}
	for (int i = 0; i < length; i++) {
		if (i < m)cin >> q[i];
		else q[i] = 0;
	}

	int* sum;
	sum = new int[length];
	int c = 0;
	for (int i = 0; i < length; i++) {
		sum[i] = p[i] + q[i] + c;
		if (sum[i] > 9) {
			sum[i] -= 10;
			c = 1;
		}
		else c = 0;
	}

	if (c)cout << c;
	for (int i = length - 1; i >= 0; i--)cout << sum[i];

	delete[]p;
	delete[]q;
	delete[]sum;

	return 0;
}