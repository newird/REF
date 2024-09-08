#include<iostream>
using namespace std;
class SeqList
{
private:int* data;
	   int size;
public:
	SeqList(int sz) {
		size = sz;
		data = new int[size];
	}
	~SeqList() { delete[] data; }
	void intput()
	{
		for (int i = 0; i < size; i++)
		{
			cin >> data[i];
		}
	}
	int Max()
	{
		int max = 0, sum = 0;
		for(int i = 0; i < size-1; i++)
		{
			for (int j = i+1; j < size; j++)
			{
				if (data[j] <= data[i])
				{
					i = j;
					break;
				}
				else
				{
					sum = data[j] - data[i];
					max = (max > sum) ? max : sum;
				}
			}
		}
		return max;
	}
};
int main()
{
	int n = 0;
	cin >> n;
	SeqList A(n);
	int max = A.Max();
	cout << max;
	return 0;
}