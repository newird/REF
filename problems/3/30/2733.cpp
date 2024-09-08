#include <iostream>
using namespace std;
#include <stdio.h>


struct Node
{
	int value;
	Node* next;
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

Node* TotalLink(Node* head_nnn, Node* head_mmm)
{
	long long total = 0;
	Node* curr_nnn = new Node;
	Node* curr_mmm = new Node;
	curr_mmm = head_mmm;
	curr_nnn = head_nnn;
	int kelipatan = 1;

	while (curr_nnn->next != NULL) //n TOTAL
	{
		total = total + curr_nnn->value * kelipatan;
		curr_nnn = curr_nnn->next;
		kelipatan = kelipatan * 10;
	}
	total = total + curr_nnn->value * kelipatan;

	kelipatan = 1;

	while (curr_mmm->next != NULL) // m TOTAL
	{
		total = total + curr_mmm->value * kelipatan;
		curr_mmm = curr_mmm->next;
		kelipatan = kelipatan * 10;
	}
	total = total + curr_mmm->value * kelipatan;

	cout << total << endl;
	return curr_mmm;
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




/*#include <iostream>
using namespace std;

long long FUNC(int n, int m);

int main()
{
	int n, m;
	long long result;
	cin >> n >> m;
	result = FUNC(n, m);
	cout << result << endl;
	return 0;
}

long long FUNC(int n, int m)
{
	long long pertama = 0;
	long long kedua = 0;
	long long kelipatansepuluh = 1;
	long long a;
	for (int i = 1; i <= n; i = i + 1)
	{
		cin >> a;
		pertama = pertama + a * kelipatansepuluh;
		kelipatansepuluh = kelipatansepuluh * 10;
	}

	kelipatansepuluh = 1;

	for (int j = 1; j <= m; j = j + 1)
	{
		cin >> a;
		kedua = kedua + a * kelipatansepuluh;
		kelipatansepuluh = kelipatansepuluh * 10;
	}

	long long total = pertama + kedua;
	return total;
}
*/