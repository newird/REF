#include<iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node* next;
}Node;

Node* Create(int len)
{
	Node* head = NULL, * tail = NULL;
	int num;
	for (int i = 0; i < len; ++i)
	{
		cin >> num;
		Node* p = new Node;
		p->data = num;
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
	return head;
}

Node* Reverse(Node* head)
{
	Node* prev = NULL;
	Node* curr = NULL;
	while (head != NULL)
	{
		prev = curr;
		curr = head;
		head = curr->next;
		curr->next = prev;
	}
	return curr;
}

void Result(Node* head1, Node* head2)
{
	int count1 = 0;
	int count2 = 0;
	Node* temp1 = head1;
	Node* temp2 = head2;
	while (temp1 != NULL)
	{
		count1 = count1 + 1;
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		count2 = count2 + 1;
		temp2 = temp2->next;
	}
	if (count1 == count2)
	{
		int sum;
		int carry = 0;
		while (head1 != NULL && head2 != NULL)
		{
			int curr = head1->data + head2->data;
			sum = (curr + carry) % 10;
			if (curr / 10 != 0)
			{
				carry = curr / 10;
			}
			cout << sum;
			head1 = head1->next;
			head2 = head2->next;
		}
	}
	else
	{
		int sub = 0;
		if (count1 > count2)
		{
			Node* first = head1;
			Node* second = head2;
			sub = count1 - count2;
			for (int i = 0; i < sub; ++i)
			{
				Node* ins = new Node;
				ins->data = 0;
				ins->next = second;
				second = ins;
			}
			int sum;
			int carry = 0;
			while (first != NULL && second != NULL)
			{
				int curr = first->data + second->data;
				sum = (curr + carry) % 10;
				if (curr / 10 != 0)
				{
					carry = curr / 10;
				}
				cout << sum;
				first = first->next;
				second = second->next;
			}
		}
		else
		{
			Node* first = head2;
			Node* second = head1;
			sub = count2 - count1;
			for (int i = 0; i < sub; ++i)
			{
				Node* ins = new Node;
				ins->data = 0;
				ins->next = second;
				second = ins;
			}
			int sum;
			int carry = 0;
			while (first != NULL && second != NULL)
			{
				int curr = first->data + second->data;
				sum = (curr + carry) % 10;
				if (curr / 10 != 0)
				{
					carry = curr / 10;
				}
				cout << sum;
				first = first->next;
				second = second->next;
			}
		}
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
	cin >> n >> m;
	Node* list1 = Create(n);
	Node* list2 = Create(m);
	list1 = Reverse(list1);
	list2 = Reverse(list2);
	Result(list1, list2);
	DeleteList(list1);
	DeleteList(list2);
	return 0;
}