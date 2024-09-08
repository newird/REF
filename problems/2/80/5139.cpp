#include<iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	int head = 0, tail = 0;
	int a[100005] = { 0 };
	int mymax = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int pro = a[j] - a[i];
			if (pro > mymax)	mymax = pro;
		}
	}
	cout << mymax;


	return 0;
}