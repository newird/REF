#include<iostream>
using namespace std;

int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}

void read_in(int num, int value[]) {
	for (int i = 0; i < num; i++) 
		cin >> value[i];
}

int main() {
	int value[100000] = { 0 };
	int num = 0;
	cin >> num;
	read_in(num, value);
	int wealth = 0;;
	int mini = value[0];
	for (int i = 0; i < num; i++) {
		if (value[i] <= mini) {
			for (int j = i + 1; j < num; j++) {
				int ans = value[j] - value[i];
				if (ans > wealth) wealth = ans;
			}
		}
	}
	cout << wealth;
	return 0;
}