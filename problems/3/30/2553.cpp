#include<iostream>
#include<vector>
using namespace std;


long long int sum(vector<int>&num1, vector<int>&num2) {
	long long int res1 = 0;
	long long int res2 = 0;
	int n1 = num1.size();
	int n2 = num2.size();
	for (int i = 0;i < n1;i++)
		res1 = res1 * 10 + num1[i];
	for (int i = 0;i < n2;i++)
		res2 = res2 * 10 + num2[i];
	return res1 + res2;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int>num1(n);
	for (int i = n - 1;i >= 0;i--)
		cin >> num1[i];
	vector<int>num2(m);
	for (int i = m - 1;i >= 0;i--)
		cin >> num2[i];
	cout << sum(num1, num2);
	return 0;
}