#include<cstdio>
#include<queue>
#include <algorithm>
#include<iostream>
using namespace std;


int main()
{
	long long  n, m, d, a;
	long long sum, ans;
	cin >> n >> m >> d;
	int* nums = new int[n];
	int head = 0;
	int in = 0;
	ans = sum = 0;
		for (long long i = 1; i <= n; ++i)
		{
			cin>>a;
			if (a < 0) continue;
			nums[in] = a;
			in++;
			std::sort(nums + head, nums + in);
			sum += a;
			if (in > m) 
			{
				sum -= nums[head];
				head++;
				
			}
			ans = max(ans, sum - d * i);
		}
		cout << ans;
		return 0;
	
}