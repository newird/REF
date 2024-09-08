#include<iostream>
#include<cstdio>
using namespace std;
struct LinkNode {
	int data;
	LinkNode* link;
	LinkNode(LinkNode* ptr = NULL) { link = ptr; }
	LinkNode(const int& item, LinkNode* ptr = NULL) {
		data = item, link = ptr;
	}
};

class List
{
private:
	LinkNode* first;
public:
	List() { first = new LinkNode; }
	~List() { makeEmpty(); }
	void makeEmpty()
	{
		LinkNode* q;
		while (first->link != NULL)
		{
			q = first->link;
			first->link = q->link;
			delete q;
		}
	}
	LinkNode* getHead()const { return first; }
	void input()
	{
		int var;
		cin >> var;
		LinkNode* p = first;
		while (p->link != NULL)
		{
			p = p->link;
		}
		LinkNode* newnode = new LinkNode;
		newnode->data = var;
		newnode->link = NULL;
		p->link = newnode;
	}
	void output()
	{
		LinkNode* current = first->link;
		while (current != NULL)
		{
			cout << current->data;
			current = current->link;
		}
	}
	void Insert(int x)
	{
		LinkNode* newnode = new LinkNode;
		newnode->data = x;
		newnode->link = first->link;
		first->link = newnode;
	}
};
List Addition(List A, List B)
{
	LinkNode* pa, * pb, * p;
	List C;
	int temp, CF = 0;
	pa = A.getHead()->link;
	pb = B.getHead()->link;
	while (pa != NULL && pb != NULL)
	{
		temp = pa->data + pb->data + CF;
		CF = temp / 10;
		temp = temp % 10;
		C.Insert(temp);
		pa = pa->link;
		pb = pb->link;
	}
	if (pa != NULL)
		p = pa;
	else
		p = pb;
	while (p != NULL)
	{
		temp = p->data + CF;
		CF = temp / 10;
		temp = temp % 10;
		C.Insert(temp);
		p = p->link;
	}
	if (CF != 0)
	{
		temp = CF % 10;
		CF = CF / 10;
		C.Insert(temp);
	}
	C.output();
	return C;
}
int main()
{
	List A, B;
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++)A.input();
	for (int i = 0; i < n; i++)B.input();
	Addition(A, B);
	return 0;
}