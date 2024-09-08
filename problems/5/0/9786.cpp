#include <iostream>
#include "stack.h"
using namespace std;

int main() {
	int n, m, d;
	cin >> n >> m >> d;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	Stack<int> s(n);
	Stack<int> temp(n);
	for (int i = n - 1; i >= 0; i--)
		if (a[i] > 0)
			s.Push(i);
	int max = 0, pre = -1, t = 0;
	for (int i = s.Size(); i > 0; i--) {
		pre = -1;
		t = 0;
		do {
			t += -d * (s.Back() - pre) + a[s.Back()];
			temp.Push(s.Back());
			pre = s.Back();
			s.Pop();
			max = max < t ? t : max;
		} while (!s.isEmpty());
		while (!temp.isEmpty()) {
			s.Push(temp.Back());
			temp.Pop();
		}
		s.Pop();
	}
	cout << max << endl;
	return 0;
}