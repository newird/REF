#include <iostream>
using namespace std;
#include <stack>

int main() {
	stack<int> s;	//栈内总是从最低价开始的升序序列

	int time;
	cin >> time;
	int input;
	cin >> input;
	s.push(input);
	int max = 0;
	int lowest = input;


	for (int i = 1; i < time; i++) {
		cin >> input;
		if (input > s.top()) {
			//当前输入涨价，压栈
			s.push(input);
		}
		else if (input == s.top()) {
			//平价
			;
		}
		else {
			//当前降价了，考虑到一个谷峰，记录峰值并清栈，记录新的底
			max = (max > (s.top() - lowest) ? max : (s.top() - lowest));
			while (s.top() >= input) {
				s.pop();
				if (s.empty()) {
					lowest = input;
					break;
				}
			}
			s.push(input);
		}
	}
	max = (max > (s.top() - lowest) ? max : (s.top() - lowest));
	cout << max;
	return 0;


}