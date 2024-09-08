#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int* P = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> P[i];
	}

	int* Q = new int[n];
	int j = 0;
	Q[0] = P[0];
	int biggest = 0;

	for (int i = 1; i < n; i++)
	{
		if (P[i] < Q[j] || P[i] == Q[j])
		{
			Q[j + 1] = P[i];
			j++;
		}
		else {
			int minus = P[i] - Q[j];

			if (minus > biggest) {
				biggest = minus;
			}
		}
	}

	cout << biggest;
	return 0;
}