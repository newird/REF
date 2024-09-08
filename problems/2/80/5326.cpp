#include<iostream>
using namespace::std;
int main()
{
	int maxofone=0;
	int maxofall = 0;
	int  n;
	int p[100000]={0};
	int stack[10000] = { 0 };
	int now = 0;
	//int pmax[100000] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	if (n < 1000) {
		for (int i = 0; i < n - 1; i++)
		{
			while (p[i + 1] < p[i])i++;
			for (int j = i + 1; j < n; j++)
			{
				if (p[j] - p[i] > maxofall)maxofall = p[j] - p[i];


			}
		}
	}
	else {
		for (int i = 0; i < n - 1; i++)
		{
			//while (i+1<n-1&&p[i + 1] < p[i])i++;
			if (now == 0) {
				stack[0] = p[i]; now++;
			}
			else
			{
				if (p[i] < stack[now - 1])
				{
					if (p[i] >= stack[0])i++;
					else if (p[i] < stack[0])
					{
						maxofone = stack[now - 1] - stack[0];
						if (maxofall < maxofone)maxofall = maxofone;
						stack[0] = p[i];
						now = 1;

					}
				}
				else if (p[i] > stack[now - 1])
				{
					stack[now] = p[i];
					now++;
				}

			}
		}
		if (now>0&&maxofall < stack[now - 1] - stack[0])maxofall = stack[now - 1] - stack[0];
	}


	cout << maxofall;


	return 0;
}