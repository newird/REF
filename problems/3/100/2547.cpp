#include <iostream>

using namespace std;

class List{
public:
    class Node{
    public:
        int val;
        Node *next;
        Node *before;
        Node(int v,Node *n = nullptr,Node *b = nullptr){
            val = v;
            next = n;
            before = b;
        };
    };
    Node *first;
    Node *rear;
    int len;
    List(){
        first = nullptr;
        rear = nullptr;
        len = 0;
    };

    void Append(int v){
        if (first == nullptr){
            first = new Node(v);
            rear = first;
        }else{
            rear->next = new Node(v);
            Node *temp = rear;
            rear = rear->next;
            rear->before = temp;
        }
        ++len;
    };
};


int main() {
    int a,b;
    cin >> a >> b;
    int input;
    List *listA = new List();
    List *listB = new List();
    for (int i = 0; i < a; ++i) {
        cin >> input;
        listA->Append(input);
    }
    for (int i = 0; i < b; ++i) {
        cin >> input;
        listB->Append(input);
    }
    List::Node *bigger;
    List::Node *lesser;
    if (a >= b){
        bigger = listA->first;
        lesser = listB->first;
    }else{
        bigger = listB->first;
        lesser = listA->first;
    }
    int carry = 0;
    int sum = 0;
    List *sumList = new List();
    while (lesser != nullptr){
        sum = lesser->val + bigger->val + carry;
        if (sum >= 10){
            sumList->Append(sum - 10);
            carry = 1;
        } else{
            sumList->Append(sum);
            carry = 0;
        }
        lesser = lesser->next;
        bigger = bigger->next;
    }
    while (bigger != nullptr){
        sum = bigger->val + carry;
        if (sum >= 10){
            sumList->Append(sum - 10);
            carry = 1;
        } else{
            sumList->Append(sum);
            carry = 0;
        }
        bigger = bigger->next;
    }
    if (carry == 1){
        sumList->Append(1);
    }
    while (sumList->rear != nullptr){
        cout << sumList->rear->val;
        sumList->rear = sumList->rear->before;
    }
}
