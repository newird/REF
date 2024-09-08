#include <iostream>
using namespace std;

int main()
{
	int n;
	int* p;
	cin >> n;
	p = new int[n];

	for (int i = 0; i < n; i++)cin >> p[i];

	int s = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (p[j] - p[i] > s)s = p[j] - p[i];
		}
	}

	cout << s;
	delete[]p;
	return 0;
}