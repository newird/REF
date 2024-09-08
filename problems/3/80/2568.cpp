#include <iostream>
using namespace std;

struct LinkNode {
	int data;
	LinkNode* next;
	LinkNode* prior;
};

int main() {
	int a, b;
	cin >> a >> b;
	LinkNode head{0, nullptr, nullptr};	//特殊头节点
	LinkNode* tail = &head;
	for (int i = 0; i < a; i++) {	//节点输入
		LinkNode* newNode = new LinkNode;
		cin >> newNode->data;
		newNode->next = nullptr;
		newNode->prior = tail;
		tail->next = newNode;
		tail = newNode;
	}
	int CF = 0;
	LinkNode* current = head.next;
	for (int i = 0; i < b; i++) {
		int input;
		cin >> input;
		if (i < a) {	//如果当前没有超出前一个链表的长度
			current->data = current->data + CF + input;
			if (current->data > 9) {
				CF = 1;
				current->data -= 10;
			}
			else
				CF = 0;
			current = current->next;	//只有没超出第一个链表长度时才需要移动current
		}
		else {	//需要新增链表
			LinkNode* newNode = new LinkNode;
			newNode->next = nullptr;
			newNode->prior = tail;
			tail->next = newNode;
			tail = tail->next;

			newNode->data = input + CF;
			if (newNode->data > 9) {
				CF = 1;
				newNode->data -= 10;
			}
		}
	}
	/*最后可能还有CF*/
	if (CF) {
		LinkNode* newNode = new LinkNode;
		newNode->data = 1;
		newNode->next = nullptr;
		newNode->prior = tail;
		tail->next = newNode;
		tail = newNode;
	}
	/*反向输出并析构*/
	while (tail != &head) {
		cout << tail->data;
		tail = tail->prior;
		delete tail->next;
	}
	return 0;
}