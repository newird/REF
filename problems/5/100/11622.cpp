#include <iostream>
using namespace std;

long long n, m, d;

long long arr[200002];
long long m1[200002];
long long res[200002] = { 0 };

void shiftdown(int start,int m_size)
{
	int i = start, j = 2 * i + 1;
	long long temp = m1[i];
	while (j <= m_size)
	{
		if (j<m_size && m1[j]>m1[j + 1])
			j++;
		if (temp <= m1[j]) break;
		else {
			m1[i] = m1[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	m1[i] = temp;
}

void shiftup(int start)
{
	int j = start,i = (j - 1) / 2;
	long long temp = m1[j];
	while (j > 0)
	{
		if (m1[i] <= temp)
			break;
		else {
			m1[j] = m1[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	m1[j] = temp;
}

void remove()
{
	m1[0] = m1[m - 1];
	m1[m - 1] = 0;
	shiftdown(0, m - 2);
}


int main()
{
	cin >> n >> m >> d;
	long long length = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (length < m && arr[i]>0)
		{
			m1[length] = arr[i];
			shiftup(length);
			length++;
			res[i + 1] = res[i] + arr[i];
		}
		else if (length == m && arr[i] > m1[0])
		{
			long long num = m1[0];
			remove();
			m1[length-1] = arr[i];
			shiftup(length - 1);
			res[i + 1] = res[i] - num + arr[i];
		}
		else {
			res[i + 1] = res[i];
		}
	}
	long long max_1 = 0;
	for (int i = 1; i <= n; i++)
	{
		res[i] -= i * d;
		if (res[i] > max_1)
		{
			max_1 = res[i];
		}
	}
	cout << max_1 << endl;
	return 0;
}