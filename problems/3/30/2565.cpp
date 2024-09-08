#include <iostream>
using namespace std;

int FUNC(int n, int m);

int main()
{
	int n, m, result;
	cin >> n >> m;
	result = FUNC(n, m);
	cout << result << endl;
	return 0;
}

int FUNC(int n, int m)
{
	int pertama = 0;
	int kedua = 0;
	int kelipatansepuluh = 1;
	int a;
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

	int total = pertama + kedua;
	return total;
}