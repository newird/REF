#include <iostream>
using namespace std;
int q[200005]={0};
int lst[200005];
int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	for (int i = 1; i <= n; ++i)
	{
		cin >> lst[i];
	}
	int front = 0, rear = m - 1;
	int ans = 0, cur_sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (lst[i] + cur_sum - i * d > ans)
			ans = lst[i] + cur_sum - i * d;
		if (lst[i] > q[front])
		{
			int p=rear;
			while (q[p - 1] > lst[i])
			{
				q[p] = q[p - 1];
				p--;
			}
			q[p] = lst[i];
			cur_sum = cur_sum - q[front] + lst[i];
			front++;
			rear++;
		}
	}
	cout << ans;
	return 0;
}