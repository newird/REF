#include <iostream>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

struct Node {
	int data, subscript;
	Node* next;
};
int Gainhappiness(Node* head, int l, int m, int d)
{
	if (head == NULL || m == 0)return 0;

	int happiness1, happiness2;
	if (l == head->subscript - 1 && l) happiness1 = Gainhappiness(head->next, head->subscript, m - 1, d) + head->data;
	else happiness1 = Gainhappiness(head->next, head->subscript, m - 1, d) + head->data - (head->subscript - l) * d;
	happiness2 = Gainhappiness(head->next, l, m, d);

	return max(happiness1, happiness2);
}
int main()
{
	int n, m, d;
	cin >> n >> m >> d;

	Node* head = NULL;

	Node* p = head;
	for (int i = 1; i <= n; i++) {
		int data;
		cin >> data;

		Node* q = new Node;
		q->data = data;
		q->subscript = i;
		q->next = NULL;
		if (i == 1)p = head = q;
		else {
			p->next = q;
			p = p->next;
		}
	}

	cout << Gainhappiness(head, 0, m, d);

	return 0;
}

