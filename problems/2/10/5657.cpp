#include <iostream>
using namespace std;

const int stackIncreament = 20;
class Stack
{
private:
	int* content;
	int top;
	int maxSize;
	void ofProcess()
	{
		int* newContent = new int[maxSize + stackIncreament];
		if (newContent == NULL) { cerr << "存储分配失败" << endl; exit(1); }
		for (int i = 0; i != top + 1; i++)
			newContent[i] = content[i];
		maxSize += stackIncreament;
		delete[]content;
	}
public:
	Stack(int sz = 10)
	{
		int* c = new int[sz];
		content = c;
		maxSize = sz;
		top = -1;
	}
	bool IsFull() const { return (top == maxSize - 1) ? true : false; }
	bool IsEmpty() const { return (top == -1) ? true : false; }
	void MakeEmpty() { top = -1; }
	bool Pop()
	{
		if (IsEmpty() == true)
			return false;
		else
		{
			//x = content[top];
			top--;
			if (top == -1)
				MakeEmpty();
			return true;
		}
	}
	bool getTop(int& x)
	{
		if (IsEmpty())
			return false;
		x = content[top];
		return true;
	}
	int& Top() { return content[top]; }
	void Push(const int& x)
	{
		if (IsFull() == true) ofProcess();
		content[++top] = x;
	}
	int getSize() { return top; }
	int Bottom()
	{
		if (IsEmpty())
			return 0;
		return content[0];
	}
};

int main()
{
	int n;
	cin >> n;
	int* p = new int[n];
	for (int i = 0; i != n; i++)
		cin >> p[i];
	int max = 0;
	Stack s;
	s.Push(p[0]);
	for (int i = 1; i != n; i++)
	{
		if (p[i] <= s.Bottom())
			while (!s.IsEmpty())
				s.Pop();
		s.Push(p[i]);
		max = (max > s.Top() - s.Bottom()) ? max : s.Top() - s.Bottom();
	}
	cout << max;
	return 0;
}