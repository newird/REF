#include <iostream>
#include<bits/stdc++.h>

using namespace std;

long long sum;
long long y = 0;
long long n;
long long m;
long long d;


typedef struct tagNode{
	int data;
	struct tagNode* next;
	struct tagNode* prev;
} Node;

int k = 0; 
bool check = false;

Node* createNode(int a);
void appendNode(Node** head, Node* newNode);
void removeNode(Node** head, Node* remove);
Node* getNode(Node* head, int location);
int cntNode(Node* head);
Node* plusDirection(Node* node);
Node* minusDirection(Node* node);
void delNode(Node* node);

vector<long long> A; 
void co(vector<long long> A);

int main() {

    cin >> n >> m >> d;
    
    for (int i = 0; i < n; i++) { // 처음 인풋 부분. 
        long long c;
        cin >> c;
        A.push_back(c);
    }
    
    co(A); // 마지막 함수 그냥 출력. 
}

Node* createNode(int a){
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = a;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	return newNode;
}

void appendNode(Node** head, Node* newNode){
	if((*head) == NULL){
		*head = newNode;
		(*head)->next = *head;
		(*head)->prev = *head; 
	} else {
		Node* tail = (*head)->prev;
		
		tail->next->prev = newNode;
		tail->next = newNode;
		
		newNode->next = (*head);
		newNode->prev = tail;
	}
}

void removeNode(Node** head, Node* remove){
	
	if(*head == remove){
		
		(*head)->prev->next = remove->next;
		(*head)->next->prev = remove->prev;
		
		*head = remove->next;
		
		remove->prev = NULL;
		remove->next = NULL;

	} else {
		
		Node* temp = remove;
		
		remove->prev->next = temp->next;
		remove->next->prev = temp->prev;
		
		remove->prev = NULL;
		remove->next = NULL;
	}
}

void delNode(Node* node){
	node->next->prev = node->prev;
	node->prev->next = node->next;
}

Node* getNode(Node* head, int location){
	Node* current = head;
	
	while(current != NULL && (--location) >= 0){
		current = current->next;
	}
	return current;
}

int cntNode(Node* head){
	int cnt = 0;
	Node* current = head;
	while(current != NULL){
		current = current->next;
		cnt++;
	}
	return cnt;
}

Node* plusDirection(Node* node){
	
	while (node->data != node->next->data){
		for (int i = 1; i < m; i++){
			if (node->data != node->next->data){
				node = node->next;
			}
		}
		if (node->data % k == 0){
			cout << node->data << " ";
			delNode(node);
			node = node->prev;
			
			check = false;	
			return node;	
		} else {
			cout << node->data << " ";
			delNode(node);
			node = node->next;
		}
	}
	return node;
}


Node* minusDirection(Node* node){
	while (node->data != node->next->data){
		for (int i = 1; i < m; i++){
			
			if (node->data != node->next->data){
				node = node->prev;
			}	
		}
		if (node->data % k == 0){
			cout << node->data << " ";
			delNode(node);
			node = node->next;
			check = true;
			
			return node;		
		}
		else{
			cout << node->data << " ";
			delNode(node);
			node = node->prev;
		}
	}
	return node;
}

void co(vector<long long> A) {
	priority_queue<long long, vector<long long>, greater<long long>> a;  //최소 큐 만들어서 사용하기. 
	
	for (int i = 0; i < n; i++) { //각 데이터들 비교 해서 하는 부분. 
        if (A[i] > 0) {
            if (a.size() < m) {
                a.push(A[i]);
                sum += A[i];
            }
            else if (A[i] > a.top()) {
                sum -= a.top();
                a.pop();
                a.push(A[i]);
                sum += A[i];
            }
            y = max(y, sum - d * (i + 1));
        }
    }
    cout << y << endl;
}