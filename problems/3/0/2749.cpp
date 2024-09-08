#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* prev;
	ListNode* next;
	ListNode() {}
	ListNode(int val) :val(val) {}
};

ListNode* sum(ListNode* head1, ListNode* head2,int c) {
	if (!head1 && !head2 && c == 0)
		return NULL;
	else if (!head1 && !head2 && c == 1) {
		ListNode* p = new ListNode(1);
		p->next = NULL;
		return p;
	}

	if (!head1 || !head2) {
		ListNode* head = head1 ? head1 : head2;
		int res = head->val + c;
		head->val = res % 10;
		c = res / 10;
		head->next = sum(head->next, NULL, c);
		return head;
	}
	
	int res = head1->val + head2->val + c;
	head1->val = res % 110;
	c = res / 10;
	head1->next = sum(head1->next, head2->next, c);
	return head1;
}

int main() {
	int n, m;
	cin >> n >> m;
	ListNode* head1 = new ListNode;
	cin >> head1->val;
	ListNode* p1 = head1;
	for (int i = 1;i < n;i++) {
		ListNode* p = new ListNode;
		cin>>p->val;
		p1->next = p;
		p->prev = p1;
		p1 = p1->next;
	}
	p1->next = NULL;
	ListNode* head2 = new ListNode;
	cin >> head2->val;
	ListNode* p2 = head2;
	for (int i = 1;i < m;i++) {
		ListNode* p = new ListNode;
		cin >> p->val;
		p2->next = p;
		p->prev = p2;
		p2 = p2->next;
	}
	p2->next = NULL;

	ListNode* head = sum(head1, head2, 0);
	head->prev = NULL;
	ListNode* tail = head;
	while (tail->next) {
		tail->next->prev = tail;
		tail = tail->next;
	}
	while (tail) {
		cout << tail->val;
		tail = tail->prev;
	}
	return 0;
}