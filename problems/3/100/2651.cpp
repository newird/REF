#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int max = (n > m) ? n : m;
	int num_n[max + 1] = {0}, num_m[max + 1] = {0};
	for (int i = 0; i < max + 1; i++) {
		if (i < n)
			cin >> num_n[i];
		else
			num_n[i] = 0;//多出的数位赋0
	}
	for (int i = 0; i < max + 1; i++) {
		if (i < m)
			cin >> num_m[i];
		else
			num_m[i] = 0;//多出的数位赋0
	}
	num_m[0] += num_n[0];//将结果存在num_m中
	for (int i = 1; i < max; i++) {
		num_m[i] += num_n[i] + num_m[i - 1] / 10;//对应数位相加，再加上前一位的进位
		num_m[i - 1] %= 10;//前一位完成进位，模10
	}
	for (int i = max; i >= 0; i--) {
		if (i < max || num_m[i] != 0)
			cout << num_m[i];
	}
	return 0;
}