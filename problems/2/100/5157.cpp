#include<assert.h>
#include<iostream>
#include<cmath>
using namespace std;

const int maxsize = 50;
const int stackIncreament = 20;//溢出时的空间增量
template<class T>
class Seqstack
{
private:
	T* elements;
	int top;
	int maxsize;
	void overflowpass() {
		T* newArray = new T[maxsize + stackIncreament];
		if (newArray == NULL)
		{
			cerr << "内存分配失败" << endl;
			exit(-1);
		}
		for (int i = 0; i <= top; i++)
			newArray[i] = elements[i];
		maxsize += stackIncreament;
		delete[]elements;
		elements = newArray;
	};
public:
	Seqstack(int sz = 50) :top(-1), maxsize(sz) {
		elements = new T[maxsize];
		assert(elements != NULL);
	};
	bool IsEmpty()const {
		return (top == -1) ? true : false;
	}
	bool Isfull()const {
		return (top == maxsize-1) ? true : false;
	}
	int getsize()const {
		return top + 1;
	}
	int get_num_top()const {
		return top;
	}
	void makeEmpty() {
		top = -1;
	}
	T gettop() {
		return elements[top];
	}
	bool getTop(T& x) {
		if (IsEmpty() == true)
			return false;
		x = elements[top];
		return true;
	};
	void push(const T& x) {
		if (Isfull() == true)
			overflowpass();
		elements[++top] = x;
	}
	bool pop(T& x) {
		if (IsEmpty() == true)
			return false;
		x = elements[top--];
		return true;
	}
};

int main()
{
	int n;
	cin >> n;
	Seqstack<int> pr;
	int x;
	int max = 0,index = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (pr.IsEmpty())
			pr.push(x);
		else
		{
			if (pr.gettop() >= x)
			{
				int fw;
				pr.pop(fw);
				pr.push(x);
			}
			else
			{
				index = x - pr.gettop();
				max = std::max(max, index);
			}
		}
	}
	cout << max;
}


