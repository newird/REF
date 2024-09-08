#include<iostream>
using namespace std;

class Big_add
{
	int n;
	int m;
	short* src1;
	short* src2;
	short* res = NULL;//result
	bool highest = 0;//最高位进位，仅在n=m时有效

public:
	Big_add()
	{
		cin >> n >> m;
		src1 = new short[n];
		src2 = new short[m];			//src:低位->高位
		for (int i = 0; i < n; i++)
			cin >> src1[i];
		for (int i = 0; i < m; i++)
			cin >> src2[i];

		//确保src1长于src2，n>=m
		if (m > n)
		{
			int t = m;
			m = n;
			n = t;
			short* temp = src1;
			src1 = src2;
			src2 = temp;
		}

		short cin = 0;
		res = new short[n];
		for (int i = 0; i < m; i++)
		{
			res[i] = src1[i] + src2[i] + cin;
			if (res[i] >= 10)
			{
				res[i] -= 10;
				cin = 1;
			}
			else cin = 0;
		}
		for (int i = m; i < n; i++)
		{
			res[i] = src1[i] + cin;
			if (res[i] >= 10)
			{
				res[i] -= 10;
				cin = 1;
			}
			else cin = 0;
		}
		highest = cin;
	}

	void output()
	{
		if (highest)
			cout << 1;
		for (int i = n - 1; i >= 0; i--)
			cout << res[i];
	}
};

int main()
{
	Big_add big_add;
	big_add.output();
	return 0;
}