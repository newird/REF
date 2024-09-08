#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* low_Node;
	Node* high_Node;
};
void link_list(int n, Node* head) {
	Node* top = head;
	head->data = 0;
	Node* p = new Node;
	p->data = 0;
	top->high_Node = p;
	top = top->high_Node;
	top->low_Node = head;
	top = head;
	for (int i = 0; i < n - 2; i++) {
		Node* q = new Node;
		q->data = 0;
		top->high_Node->high_Node = q;
		top->high_Node->high_Node->low_Node = top->high_Node;
		top = top->high_Node;
	}
	top = top->high_Node;
	top->high_Node = NULL;
	//cout << 2;
};
void cin_list(int n, Node* head) {
	Node* top = head;
	for (int i = 0; i < n; i++) {
		cin >> top->data;
		top = top->high_Node;
	}
}
void add_list(Node* head1, Node* head2, Node* head3,int outnum) {
	Node* top1, * top2, * top3;
	top1 = head1; top2 = head2; top3 = head3;
	for (int i = 0; i < outnum - 1; i++) {
		if (top1->data + top2->data >= 10) {
			top3->data = top3->data + top1->data + top2->data - 10;
			top3->high_Node->data += 1;}
		else top3->data = top3->data + top1->data + top2->data;
		top1 = top1->high_Node; top2 = top2->high_Node; top3 = top3->high_Node;
	}
}
void cout_list(Node* head,int outnum) {
	Node* top = head;
	while (top->high_Node != NULL) top = top->high_Node;
	if (top->data == 0) {
		top = top->low_Node;
		for (int i = 0; i < outnum - 1; i++) {
			cout << top->data;
			top = top->low_Node;
		}
	}
	else {
		for (int i = 0; i < outnum; i++) {
			cout << top->data;
			top = top->low_Node;
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	int outnum;
	Node head1, head2, head3;
	if (n >= m) { 
		link_list(n + 1, &head1); link_list(n + 1, &head2);link_list(n + 1, &head3); 
		outnum = n + 1; }
	else if (n < m) {
		link_list(m + 1, &head1); link_list(m + 1, &head2); link_list(m + 1, &head3);
		outnum = m + 1;	}
	cin_list(n, &head1); cin_list(m, &head2);
	add_list(&head1, &head2, &head3, outnum);
	cout_list(&head3, outnum);
	return 0;
}