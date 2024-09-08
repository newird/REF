#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
};

long long int sum(ListNode* head1, ListNode* head2,int c) {
	if (!head1 && !head2) 
		return c;
	if (!head1 || !head2){
		ListNode* head = head1 ? head1 : head2;
		return (head->val + c) % 10 + 10 * sum(NULL, head->next, (head->val + c) / 10);
	}

	return (head1->val + head2->val + c) % 10 + 10 * sum(head1->next, head2->next, (head1->val + head2->val + c) / 10);
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
		p2 = p2->next;
	}
	p2->next = NULL;
	cout << sum(head1, head2, 0);
	return 0;
}