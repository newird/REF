#include <iostream>
using namespace std;
int max_int(int a, int b)
{
	return a > b ? a : b;
}
class small_root
{
public:
	int* a;
	int maxsize;
	int len;
	small_root(int m)
	{
		maxsize = m;
		a = new int[len];
		len = 0;
	}
	int top() { return a[0]; }
	void adjustdown()
	{
		int i = 0;
		int j = 2 * i - 1;
		int t = a[0];
		while (j < maxsize)
		{
			if (j < maxsize - 1 && a[j] > a[j + 1]) {
				j++;
			}
			if (t <= a[j]) {
				break;
			}
			else {
				a[i] = a[j];
				i = j;
				j = 2 * j + 1;
			}
		}
		a[i] = t;
	}
	void adjustup(int start)
	{
		int j = start, i = (j - 1) / 2;
		int temp = a[j];
		while (j > 0) {
			if (a[i] <= temp)
			{
				break;
			}
			else {
				a[j] = a[i];
				j = i;
				i = (i - 1) / 2;
			}
		}
		a[j] = temp;
	}
	void insert(int& data) {
		if (len < maxsize) {
			a[len] = data;
			adjustup(len);
			len++;
		}
		else if (data >a[0]) {
			
			a[0] = data;
			adjustdown();
		}
	}
	int getsum()
	{
		int sum = 0;
		for (int i = 0; i < len; ++i)
		{
			sum += a[i];
		}
		return sum;
	}
};




int main() {
	int n, m, d;
	cin >> n >> m >> d;

	small_root h(m - 1);
	int res = 0;
	int now;
	for (int i = 1; i <= n; i++) 
	{	
		cin >> now;
		if (now > 0)
		{	
			res = max_int(res, (h.getsum() + now - d * i));
			h.insert(now);
		}
	}
	cout << res;
	return 0;
}