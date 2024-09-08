#include<iostream>
using namespace std;
inline void readint(int& a) {
	a = 0; char c; int sgn = 1;
	while ((c = getchar()) < 48) if (c == '-') sgn = -1;
	do a = a * 10 + (c ^ 48);
	while ((c = getchar()) > 47);
	a *= sgn;
}
int* flag;
int* a;
long maxA = 0;
int max_a(int pos, int n,int m,int d)
{
	//pos 是上一次看的i，初始为0
	if (m == 0)
		return 0;
	else if (pos >= n)
		return 0;
	long temp_a = 0, loss;
	for (int i = pos + 1; i <= n; i++)
		if (flag[i] == 1)
			continue;
		else
		{
			flag[i] = 1;
			loss = d * (i - pos);
			temp_a = max(temp_a, max_a(i, n, m - 1, d) + a[i] - loss);
			flag[i] = 0;
		}
	return temp_a;
}
int main() {
	int n, m, d;
	readint(n), readint(m), readint(d);
	a = new int[n + 1];//第i部电影幸福值
	flag = new int[n + 1];  //是否看了第i部电影
	a[0] = flag[0] = 0;
	for (int i = 1; i <= n; i++)
		readint(a[i]), flag[i] = 0;
	cout << max_a(0, n, m, d);
}