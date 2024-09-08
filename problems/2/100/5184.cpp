#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int now_in=-1;
	int now_out=-1;
	int max_p = 0;
	int* price = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> price[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if (now_in == -1)
		{
			now_in = price[i];
			now_out = price[i];
		}
		else if (now_in > price[i])
		{
			now_in = price[i];
				now_out = price[i];
		}
		if (now_out == -1)
		{
			now_out = price[i];
		}
		else if (now_out < price[i])
		{
			now_out = price[i];
		}
		else
		{
			max_p = max_p > now_out - now_in ? max_p : now_out - now_in;
			
		}
	}
	cout << max_p;
	return 0;
}