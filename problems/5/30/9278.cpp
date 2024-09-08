#include <iostream>
using namespace std;


int main() {
	int n, m, d;
	cin >> n >> m >> d;
	int* a = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int** h = new int* [2];
	h[0] = new int[n];//存放第i天不去的最大幸福值
	h[1] = new int[n];//存放第i天去的最大幸福值
	h[0][0] = 0;
	h[1][0] = a[0] - d;
	int former0 = 0, m0 = m;
	int former1 = 1, m1 = m-1;
	int i;
	for (i = 1; i < n && m0 > 0 && m1 > 0; ++i) {
		int tempf0 = former0, tempf1 = former1, tempm0 = m0, tempm1 = m1;
		if (h[0][i - 1] > h[1][i - 1]) {//前一天不去，今天也不去
			h[0][i] = h[0][i - 1];
		}
		else {//前一天去，今天不去
			h[0][i] = h[1][i - 1];
			former0 = i;
			m0 = tempm1;
		}

		int flag = 0;
		if ((h[1][i - 1] + a[i] - d * (i + 1 - former1)) > (h[0][i - 1] + a[i] - d * (i + 1 - former0))) {//前一天去，今天也去
			if (tempm1 > 0)
			{
				h[1][i] = h[1][i - 1] + a[i] - d * (i + 1 - former1);
				former1 = i + 1;
				m1--;
				flag = 1;
			}
		}
		else if (flag == 0) {//前一天不去，今天去
			if (tempm0 > 0)
			{
				h[1][i] = h[0][i - 1] + a[i] - d * (i + 1 - former0);
				former1 = i + 1;
				m1 = tempm0 - 1;
				flag = 1;
			}
		}
		if (flag == 0) {//次数用完
			h[1][i] = h[0][i - 1] > h[1][i - 1] ? h[0][i - 1] : h[1][i - 1];
		}
	}

	int res = h[0][i - 1] > h[1][i - 1] ? h[0][i - 1] : h[1][i - 1];
	cout << res;
	return 0;
}