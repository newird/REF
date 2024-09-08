#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int price[n] = {};
	int in = 100001;
	int out = 0;
	int res = 0;
	for(int i = 0;i < n;i++)
	{
		cin >> price[i];
		if(in > price[i])
		{
			in = price[i];
			out = price[i];
		}else
		{
			if(price[i] > out)
			{
				out = price[i];
			}
		}
		res = max(res,out - in);
	}
	
	cout << res << endl;
	
	
	return 0;
}


