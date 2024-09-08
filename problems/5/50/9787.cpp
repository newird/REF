#include <iostream>
using namespace std;
template<class T>

class Stack {
	private:
		T *p;
		int top = -1;
		int max_size;
	public:
		Stack(int n) {
			max_size = n;
			p = new T[n];
		}
		~Stack() {
			delete[] p;
		}
		//入栈
		void Push(T c) {
			if (!isFull()) {
				top++;
				p[top] = c;
			} else {
				std::cout << "Stack.Push() failed, Stack is Full!" << std::endl;
				exit(-1);
			}
		}
		//出栈
		void Pop() {
			if (!isEmpty()) {
				top--;
			} else {
				std::cout << "Stack.Pop() failed, Stack is empty!" << std::endl;
				exit(-2);
			}
		}
		//读栈顶元素
		T Back() {
			if (!isEmpty()) {
				return p[top];
			} else {
				std::cout << "Stack.Back() failed, Stack is empty!" << std::endl;
				exit(-3);
			}
		}
		int Size() {
			return top + 1;
		}
		//判栈空
		bool isEmpty() {
			return top == -1;
		}
		//判栈满
		bool isFull() {
			return top == max_size - 1;
		}
};

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