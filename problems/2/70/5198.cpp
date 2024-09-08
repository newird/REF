#include<iostream>
using namespace std;
struct Node {
	int num;
	int value;
	Node* next;
};

int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}

void read_in(int num, Node* head) {
	Node* top = new Node;
	head->num = 0;
	cin >> head->value;
	top = head;
	for (int i = 1; i < num; i++) {
		Node* p = new Node;
		p->num = i;
		cin >> p->value;
		top->next = p;
		top = top->next;
	}
	top->next = nullptr;
}

int main() {
	int num = 0;
	cin >> num;
	Node* head = new Node;
	read_in(num, head);
	int wealth = 0;;
	Node* top = head;
	while (top != nullptr) {
		Node* p = top->next;
		while (p != nullptr) {
			if (p->value > top->value) {
				wealth = max(wealth, p->value - top->value);
				p = p->next;
			}
			else p = p->next;
		}
		top = top->next;
	}
	cout << wealth;
	return 0;
}