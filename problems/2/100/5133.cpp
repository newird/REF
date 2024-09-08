#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>stack;
	int max=0;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		while (!stack.empty() && stack.back() >= temp) {
			stack.pop_back();
		}
		stack.push_back(temp);
		max = temp - stack[0] > max ? temp - stack[0] : max;
	}
	cout << max;
}