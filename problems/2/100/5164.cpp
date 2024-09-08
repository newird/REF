#include <iostream>
using namespace std;

class SeqStack {
private:
	int top;
	int *elements;
	int maxsize;
	void overflowProcess() {
		int *newArray = new int[2 * maxsize];
		for (int i = 0;i <= top;i++)
			newArray[i] = elements[i];
		maxsize += maxsize;
			delete[]elements;
		elements = newArray;
	}
public:
	SeqStack(int sz) :top(-1), maxsize(sz) {
		elements = new int[maxsize];
	}
	void Push(int x) {
		if (IsFull() ==true) overflowProcess();
		top++;
		elements[top] = x;
	}
	int Pop() {
		if (IsEmpty() == true) return false;
		top--;
		return true;
	}
	int getTop() {
		if (IsEmpty() == true)return false;
		return elements[top];
	}
	int IsEmpty()const { return top == -1; }
	int IsFull()const { return top == maxsize - 1; }
	void makeEmpty() { top = -1; }
};
 

int main() {
	int n = 0,pro=0;	
	cin >> n;
	SeqStack s(n);

	for (int i = 0;i < n;i++) {
		int cur = 0;
		cin >> cur;
		if (s.IsEmpty() == true)
			s.Push(cur);
		else if (cur < s.getTop() || cur == s.getTop())
			s.Push(cur);
		else 
			pro = max(pro, cur - s.getTop());		
	}
	cout << pro << endl;
	return 0;
}