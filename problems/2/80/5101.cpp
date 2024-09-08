#include<iostream>
#include<cmath>
#include<map>
using namespace std;

class list {
protected:
	int* data;
	int size;
	int last;
public:
	list(int s) {
		size = s;
		last = -1;
		data = new int[size];
		if (data == NULL)
		{
			cout << NULL; exit(1);
		}
	}
	~list() {
		delete[]data;
	}
	bool insert(int i,int& x) {
		for (int j = last; j >= i; j--)
			data[j + 1] = data[j];
		data[i] = x;
		last++;
		return true;
	}
	bool remove(int i) {
		if (last == -1)return false;
		for (int j = i; j <= last; j++)
			data[j - 1] = data[j];
		last--;
		return true;
	}
	int getdata(int i) {
		return data[i];
	}
	long long int getlast() {
		return last;
	}
	void Print() {
		for (int i = 0; i < size; i++)
			cout << data[i] << " ";
		cout << endl;
	}
};

int main() {
	int n;
	cin >> n;
	int* pr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> pr[i];
	}
	int max = 0, index = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (pr[j] - pr[i] > 0)
				index = pr[j] - pr[i];
			max = std::max(max, index);
		}
	}
	cout << max;
}