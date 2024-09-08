#include <iostream>
using namespace std;

struct intnode {
public:
	int num;
	intnode* next;//正序进位累加
	intnode* pre;//逆序输出
	intnode(int i) : num(i), next(nullptr) {};
};

struct integer {
private:
	intnode* first;
	intnode* last;
public:
	integer() {
		first = new intnode(-1);
		last = first;
	}
	void push(int i) {
		intnode*  numnext = new intnode(i);
		last->next = numnext;
		numnext->pre = last;
		last = numnext;
	}
	intnode* getfirst() {
		return first;
	}
	intnode* getlast() {
		return last;
	}
	void add(integer* that) //add that to this
	{
		intnode* thisp = first;
		intnode* thatp = that->getfirst();
		int CF = 0;
		int temp;
		while (thisp->next!=nullptr&&thatp->next!=nullptr) {
			thisp = thisp->next;
			thatp = thatp->next;
			temp = thisp->num + thatp->num + CF;
			thisp->num = temp % 10;
			CF = temp / 10;
		}
		if (thatp->next == nullptr) {
			while (CF) {
				if (thisp->next != nullptr) {
					thisp = thisp->next;
					temp = thisp->num + CF;
					thisp->num = temp % 10;
					CF = temp / 10;
				}
				else {
					thisp->next=new intnode(CF);
					thisp->next->pre = thisp;
					last = thisp->next;
					CF = 0;
				}
			}
			return;
		}
		if (thisp->next == nullptr) {
			if (thatp->next == nullptr && CF != 0) {
				thisp->next = new intnode(CF);
				thisp->next->pre = thisp;
				last = thisp->next;
				CF = 0;
				return;
			}
			else if (thatp->next == nullptr && CF == 0) return;
			else //that后面还有
			{
				thisp->next = thatp->next;
				thatp->next->pre = thisp;
				last = that->getlast();
				while (CF) {
					if (thisp->next != nullptr) {
						thisp = thisp->next;
						temp = thisp->num + CF;
						thisp->num = temp % 10;
						CF = temp / 10;
					}
					else {
						thisp->next = new intnode(CF);
						thisp->next->pre = thisp;
						last = thisp->next;
						CF = 0;
					}
				}
			}
			return;
		}
	}
	void print() {
		intnode* curp = last;
		while (true) {
			cout<<curp->num;
			if (curp->pre->num!=-1) {
				curp = curp->pre;
			}
			else break;
		}
		cout << endl;
	}


};

int main()
{
	int n, m;
	integer* A= new integer();
	integer* B = new integer();
	int temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		A->push(temp);
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		B->push(temp);
	}
	A->add(B);
	A->print();
	return 0;
}
