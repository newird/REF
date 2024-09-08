#include<iostream>
using namespace std;

typedef struct Link {
	int val;
	Link* next;
};

Link* Create(int n)
{
	int x;
	Link* head = NULL;
	Link* tail = NULL;
	while (n) {
		Link* p = new Link;
		cin >> x;
		p->val = x;
		p->next = NULL;
		if (head == NULL) {
			head = p;
		}
		else {
			tail->next = p;
		}
		tail = p;
		n--;
	}
	return head;
}

void Printlist(Link* head)
{
	if (head == NULL) {
		cout << "\n";
	}
	else {
		while (head) {
			cout << head->val;
			head = head->next;
		}
		cout << "\n";
	}
}

Link* addtwoLink(Link* a, Link* b)
{
	Link* res = NULL;
	Link* current = NULL;
	int carry = 0;
	while (a != NULL || b != NULL) {
		int sum = carry;
		if (a != NULL) {
			sum += a->val;
			a = a->next;
		}
		if (b != NULL) {
			sum += b->val;
			b = b->next;
		}
		carry = sum / 10;
		sum = sum % 10;

		if (res == NULL) {
			res = new Link;
			res->val = sum;
			res -> next = NULL;
			current = res;
		}
		else {
			current->next = new Link;
			current = current->next;
			current->val = sum;
			current->next = NULL;
		}
	}
	if (carry > 0) {
		current->next = new Link;
		current = current->next;
		current->val = carry;
		current->next = NULL;
	}
	return res;
}

Link* reverse(Link* head)
{
	if (head == NULL || head->next == NULL) {
		return head;
	}
	else {
		Link* new_head = reverse(head->next);
		head->next->next = head;
		head->next = NULL;
		return new_head;
	}
}

int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	Link* a = Create(n);
	Link* b = Create(m);
	Link* ans = addtwoLink(a, b);
	Link* ans2 = reverse(ans);
	Printlist(ans2);
	return 0;
}