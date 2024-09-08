#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>data(n);
	for (int i = 0;i < n;i++)
		cin >> data[i];
	int largest = 0, minest = 0;
	for (int i = 1;i < n;i++) {
		if (data[i] < data[minest])
			minest=i;
		else
			largest = max(data[i] - data[minest],largest);
	}
	cout << largest;
	return 0;
}