#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int lst[400005];
int n, m, d;
 void insert(long long *h,long long x)
 {
 	int i = m-1;
 	while (h[i / 2] > x)
 	{
 		h[i] = h[i / 2];
 		i = i / 2;
 	}
 	h[i] = x;
 }
  long long pop(long long* h)
 {
 	long long res = h[1];
 	int prev = 1;
 	long long temp = h[m-1];
 	while (prev * 2 <= m-1)
 	{
 		int cur = prev * 2;
 		if (cur < m-1 && h[cur] > h[cur + 1])
 			cur++;
 		if (h[cur] > temp)
 			break;
 		h[prev] = h[cur];
 		prev = cur;
 	}
 	h[prev] = temp;
 	return res;
 }
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	long long* h = new long long[m]();
    h[0] = 0xFFFFFFFFFFFFFFFFLL;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&lst[i]);
	}
	long long ans = 0, cur_sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (lst[i] + cur_sum - i * d > ans)
			ans = lst[i] + cur_sum - i * d;
		if (lst[i] > h[1])
		{
			long long front=pop(h);
			insert(h, lst[i]);
			cur_sum = cur_sum - front + lst[i];
		}
	}
	printf("%lld", ans);
	return 0;
}
