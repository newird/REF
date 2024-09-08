#include <iostream>
using namespace std;
#include <stdio.h>


struct Node
{
	int value;
	Node* next;
	long long total;
};

Node* Create(int n)
{
	int numb;
	Node* head = NULL, * tail = NULL;
	for (int i = 0; i < n; i = i + 1)
	{
		Node* temp = new Node;
		cin >> numb;
		temp->value = numb;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}

		else
		{
			tail->next = temp;
			tail = tail->next;
		}
	}
	return head;
}

Node* TotalLink(Node* headnnn, Node* headmmm)
{
	long long total = 0;
	Node* currnnn = new Node;
	Node* currmmm = new Node;
	currmmm = headmmm;
	currnnn = headnnn;
	int kelipatan = 1;
	while (currnnn->next != NULL)
	{
		total = total + currnnn->value * kelipatan;
		currnnn = currnnn->next;
		kelipatan = kelipatan * 10;
	}
	total = total + currnnn->value * kelipatan ;
	kelipatan = 1;
	while (currmmm->next != NULL)
	{
		total = total + currmmm->value * kelipatan;
		currmmm = currmmm->next;
		kelipatan = kelipatan * 10;
	}
	total = total + currmmm->value * kelipatan;
	cout << total << endl;
	return currmmm;
}

Node* PrintNode(Node* head)
{
	Node* temp = new Node;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->value;
		temp = temp->next;
	}
	return temp;
}

Node* DeleteList(Node* head)
{
	Node* temp = new Node;
	while (head->next != 0)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	return head;
}




int main()
{
	int n, m;
	cin >> n >> m;
	Node* nnn = new Node;
	Node* mmm = new Node;
	nnn = Create(n);
	mmm = Create(m);
	TotalLink(nnn, mmm);
	DeleteList(nnn);
	DeleteList(mmm);
	return 0;
}