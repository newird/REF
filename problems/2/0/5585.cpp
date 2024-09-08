#include<iostream>
#include<stack>
using namespace std;

#define MAXSIZE 0xfff

template<class T>
class Mystack {
	int top;
	T* mys;
	int maxsize;

public:
	Mystack() :top(-1), maxsize(MAXSIZE) {
		mys = new T[maxsize];
	}
	Mystack(int size) :top(-1), maxsize(size) {
		mys = new T[maxsize];
	}

	bool Empty();
	void Push(T t);
	T Top();
	void Pop();
	int Size();
};


template<class T>
bool Mystack<T>::Empty() {
	if (top == -1) return true;
	else return false;
}
template<class T>
void Mystack<T>::Push(T t) {
	if (top + 1 < maxsize) {
		top++;
		mys[top] = t;
	}
}
template<class T>
T Mystack<T>::Top() {
	if (top > -1) {
		return mys[top];
	}
}
template<class T>
void Mystack<T>::Pop() {
	if (top > -1) {
		top--;
	}
}
template<class T>
int Mystack<T>::Size() {
	return top + 1;
}


int lmax(int a, int b) {
	return a > b ? a : b;
}


int main() {
	Mystack<int>q;
	int n;
	cin >> n;
	int mymax=0;
	int b = 0;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;

		if (q.Empty()) { 
			q.Push(m);
			b = m;
		}
		else {
			int t = q.Top();
			q.Pop();
			if (q.Empty()) {
				if (t > m) {
					q.Push(m);
					b = m;
				}
				else {
					q.Push(t);
					q.Push(m);
					b = t;
				}
			}
			else {
				if (t > m) {
					mymax = lmax(t - b, mymax);
					t = q.Top();
					while (t > m) {
						q.Pop();
						t = q.Top();
					}
					q.Push(m);
				}
				else {
					q.Push(t);
					q.Push(m);
				}
			}
		}
	}
	int t = q.Top();
	mymax = lmax(mymax, t-b);
	cout << mymax;

	return 0;
}