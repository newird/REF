#include <iostream>

using namespace std;

class List{
public:
    class Node{
    public:
        int val;
        Node *next;
        Node(int v,Node *n = nullptr){
            val = v;
            next = n;
        };
    };
    Node *first;
    int len;
    List(){
        first = nullptr;
        len = 0;
    };

    void Append(int v){
        Node *a = new Node(v,first);
        first = a;
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
    List *bigger;
    List *lesser;
    if (a >= b){
        bigger = listA;
        lesser = listB;
    }else{
        bigger = listB;
        lesser = listA;
    }
    for (int i = 0; i < bigger->len - lesser->len; ++i) {
        cout << bigger->first->val;
        bigger->first = bigger->first->next;
    }
    for (int i = 0; i < lesser->len; ++i) {
        cout << (bigger->first->val + lesser->first->val);
        bigger->first = bigger->first->next;
        lesser->first = lesser->first->next;
    }
}

public:
    class Node{
    public:
        int val;
        Node *next;
        Node(int v,Node *n = nullptr){
            val = v;
            next = n;
        };
    };
    Node *first;
    int len;
    List(){
        first = nullptr;
        len = 0;
    };

    void Append(int v){
        Node *a = new Node(v,first);
        first = a;
        ++len;
    };
};


int main() {
    int a,b;
    cin >> a,b;
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
    List *bigger;
    List *lesser;
    if (a >= b){
        bigger = listA;
        lesser = listB;
    }else{
        bigger = listB;
        lesser = listA;
    }
    for (int i = 0; i < bigger->len - lesser->len; ++i) {
        cout << bigger->first->val;
        bigger->first = bigger->first->next;
    }
    for (int i = 0; i < lesser->len; ++i) {
        cout << (bigger->first->val + lesser->first->val);
        bigger->first = bigger->first->next;
        lesser->first = lesser->first->next;
    }
}
