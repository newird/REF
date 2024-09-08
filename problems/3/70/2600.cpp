#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next=nullptr;
	ListNode* pre=nullptr;
	ListNode() : val(-1){}
	ListNode(int x) : val(x){}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};
ListNode* Init_Number(int n)
{
	ListNode* first = new ListNode();
	ListNode* curr = first;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		curr->next = new ListNode(temp);
		curr = curr->next;
	}
	return first;
}
ListNode* Add_Number(ListNode* a, ListNode* b)
{
	ListNode* last = new ListNode();
	ListNode* curr = last;
	a = a->next; b = b->next;
	int cin=0;
	while (a != nullptr && b != nullptr)
	{
		
		curr->pre = new ListNode((a->val + b->val + cin)%10,curr);
		if (a->val + b->val + cin >= 10)
			cin = 1;
		else
			cin = 0;
		curr = curr->pre; a = a->next; b = b->next;
	}
	if (a == nullptr)
	{
		while (b != nullptr)
		{
			curr->pre = new ListNode((b->val + cin)%10, curr);
			if (b->val + cin >= 10)
				cin = 1;
			else
				cin = 0;
			curr = curr->pre;
			b = b->next;
		}
	}
	else
	{
		while (a != nullptr)
		{
			curr->pre = new ListNode(a->val + cin, curr);
			if (a->val + cin >= 10)
				cin = 1;
			else
				cin = 0;
			curr = curr->pre;
			a = a->next;
		}
	}
	return curr;
}
void Print_Number(ListNode* a)
{
	while (a->val != -1)
	{
		cout << a->val;
		a = a->next;
	}
}
int main()
{
	int m, n;
	cin >> m >> n;
	ListNode* a, * b,*c;
	a = Init_Number(m);
	b = Init_Number(n);
	c = Add_Number(a, b);
	Print_Number(c);
}