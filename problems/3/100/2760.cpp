#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
};

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	node* head1 = new node;
	node* tail1=head1;
	for (int i = 0; i < n1; i++) {
		node*p = new node;
		int num = 0;
		cin >> num;
		p->data = num;
		p->next = NULL;
		tail1->next = p;
		tail1 = p;

	}

	node* head2 = new node;
	node* tail2 = head2;
	for (int i = 0; i < n2; i++) {
		node* p = new node;
		int num = 0;
		cin >> num;
		p->data = num;
		p->next = NULL;
		tail2->next = p;
		tail2 = p;

	}
	int cin = 0;
	int i = n1 > n2 ? n1 : n2;//较大的
	int* res = new int[i + 1];
	node* p1 = head1->next;
	node* p2 = head2->next;
	for (int j = 0; j < i; j++) {
		int temp = 0;
		if (p1 != NULL && p2 != NULL) {
			temp = p1->data + p2->data + cin;
			if (temp >= 10)cin = 1;
			else cin = 0;
			res[j] = temp % 10;
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1 != NULL && p2 == NULL) {
			temp = p1->data + cin;
			if (temp >= 10)cin = 1;
			else cin = 0;
			res[j] = temp % 10;
			p1 = p1->next;
		}
		else {
			temp = p2->data + cin;
			if (temp >= 10)cin = 1;
			else cin = 0;
			res[j] = temp % 10;
			p2 = p2->next;
		}

	}
	if (cin == 1) {
		res[i] = 1;
		for (int f = 0; f < i + 1; f++) {
			cout << res[i - f];
		}
	}
	else{
		for (int f = 0; f < i ; f++) {
			cout << res[i - f-1];
		}
	}
	
}