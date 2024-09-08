#include <iostream>
using namespace std;

long long FUNC(int n, int m);

int main()
{
	int n, m;
	long long result;
	cin >> n >> m;
	result = FUNC(n, m);
	cout << result << endl;
	return 0;
}

long long FUNC(int n, int m)
{
	long long pertama = 0;
	long long kedua = 0;
	long long kelipatansepuluh = 1;
	long long a;
	for (int i = 1; i <= n; i = i + 1)
	{
		cin >> a;
		pertama = pertama + a * kelipatansepuluh;
		kelipatansepuluh = kelipatansepuluh * 10;
	}

	kelipatansepuluh = 1;

	for (int j = 1; j <= m; j = j + 1)
	{
		cin >> a;
		kedua = kedua + a * kelipatansepuluh;
		kelipatansepuluh = kelipatansepuluh * 10;
	}

	long long total = pertama + kedua;
	return total;
}