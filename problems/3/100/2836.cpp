#include<iostream>
using namespace std;
class ListNode
{
public:
	int value;
	ListNode* pre;
	ListNode* next;
	ListNode(int a)
	{
		pre = nullptr;
		next = nullptr;
		value = a;
	}
	ListNode()
	{
		pre = nullptr;
		next = nullptr;
	}
};
void MyAdd(ListNode* headn, ListNode* headm, int n, int m)
{
	bool FC = false;
	int minx = min(m, n);
	int value1;
	ListNode* headsum = new ListNode;
	ListNode* n1 = headn->next;
	ListNode* m1 = headm->next;
	headn = headn->pre;
	headm = headm->pre;
	if (m >= n)
	{
		for (int i = minx; i > 0; i--)
		{
			value1 = headn->value + headm->value + (int)FC;
			FC = false;
			if (value1 > 9)
			{
				FC = true;
				value1 -= 10;
			}
			ListNode* l = new ListNode(value1);
			l->next = headsum->next;
			headsum->next = l;
			headn = headn->pre;
			headm = headm->pre;
		}
		for (int i = 0; i < m-n; ++i)
		{
			headm->value = headm->value + (int)FC;
			FC = false;
			if (headm->value > 9)
			{
				headm->value -= 10;
				FC = true;
			}
			ListNode* temp = new ListNode(headm->value);
			temp->next = headsum->next;
			headsum->next = temp;
			headm = headm->pre;
		}
		if (FC)
		{
			cout << "1";
		}
		headsum = headsum->next;
		for (int i = 0; i < m; ++i)
		{
			cout << headsum->value;
			headsum = headsum->next;
		}
	}
	if (m < n)
	{
		for (int i = minx; i > 0; i--)
		{
			value1 = headn->value + headm->value + (int)FC;
			FC = false;
			if (value1 > 9)
			{
				FC = true;
				value1 -= 10;
			}
			ListNode* l = new ListNode(value1);
			l->next = headsum->next;
			headsum->next = l;
			headn = headn->pre;
			headm = headm->pre;
		}
		for (int i = 0; i < n - m; ++i)
		{
			headn->value = headn->value + (int)FC;
			FC = false;
			if (headn->value > 9)
			{
				headn->value -= 10;
				FC = true;
			}
			ListNode* temp = new ListNode(headn->value);
			temp->next = headsum->next;
			headsum->next = temp;
			headn = headn->pre;
		}
		if (FC)
		{
			cout << "1";
		}
		headsum = headsum->next;
		for (int i = 0; i < n; ++i)
		{
			cout << headsum->value;
			headsum = headsum->next;
		}
	}
}
int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	int temp;
	ListNode* headn = new ListNode;
	ListNode* headm = new ListNode;
	headn->pre = headn;
	headn->next = headn;
	headm->pre = headm;
	headm->next = headm;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		ListNode* l1 = new ListNode(temp);
		if (headn->next == nullptr)
		{
			headn->pre = l1;
		}
		l1->pre = headn;
		headn->next->pre = l1;
		l1->next = headn->next;
		headn->next = l1;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> temp;
		ListNode* l2 = new ListNode(temp);
		if (headm->next == nullptr)
		{
			headm->pre = l2;
		}
		l2->pre = headm;
		headm->next->pre = l2;
		l2->next = headm->next;
		headm->next = l2;
	}
	MyAdd(headn, headm, n, m);
	return 0;
}