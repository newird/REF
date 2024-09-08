#include <iostream>
using namespace std;

int money(int price[10000], int num) {
	int res = 0;
	int start = 0;
	for (int i = 1; i < num; i++) {
		int tmp = 0;
		if (price[i] <= price[start]) {
			start = i;
		}
		else if (price[i] > price[start]) {
			tmp = price[i] - price[start];
			if (tmp > res) {
				res = tmp;
			}
		}
	}
	return res;
}

int main()
{
	int num;
	cin >> num;
	int price[10000];
	for (int i = 0; i < 10000; i++) {
		price[i] = 0;
	}
	for (int i = 0; i < num; i++) {
		cin >> price[i];
	}
	int res = 0;
	res = money(price, num);
	cout << res;
	return 0;
}



