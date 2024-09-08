#include<iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node* next;
}Node;

Node* Create(int asli, int len)
{
	Node* head = NULL, * tail = NULL;
	int num;
	for (int i = 0; i < len; ++i)
	{
		Node* p = new Node;
		p->data = 0;
		p->next = NULL;
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			tail->next = p;
		}
		tail = p;
	}
	Node* temp = head;
	for (int i = 0; i < asli; ++i)
	{
		cin >> num;
		temp->data = num;
		temp = temp->next;
	}
	return head;
}

Node* Result(Node* head1, Node* head2)
{
	int sum;
	int carry = 0;
	Node* top = NULL;
	while (head1 != NULL && head2 != NULL)
	{
		Node* p = new Node;
		int curr = head1->data + head2->data;
		sum = (curr + carry) % 10;
		if (curr / 10 != 0)
		{
			carry = curr / 10;
		}
		p->data = sum;
		p->next = top;
		top = p;
		head1 = head1->next;
		head2 = head2->next;
	}
	if (head1 == NULL && head2 == NULL && carry != 0)
	{
		sum = carry;
		cout << sum;
	}
	return top;
}

void OutputList(Node* head)
{
	while (head->data == 0)
	{
		head = head->next;
	}
	while (head != NULL)
	{
		cout << head->data;
		head = head->next;
	}
}

void DeleteList(Node* head)
{
	Node* current;
	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

int main()
{
	int n, m;
	int len = 0;
	cin >> n >> m;
	len = n;
	if (n < m)
	{
		len = m;
	}
	Node* list1 = Create(n,len);
	Node* list2 = Create(m,len);
	Node* finalist = Result(list1, list2);
	OutputList(finalist);
	DeleteList(list1);
	DeleteList(list2);
	DeleteList(finalist);
	return 0;
}