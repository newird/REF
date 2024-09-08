#include<iostream>
using namespace std;

class ListNode
{
public:
    int value;
    ListNode* pre;
    ListNode* next;
    ListNode(int a)
    {
        pre = nullptr;
        next = nullptr;
        value = a;
    }
    ListNode()
    {
        pre = nullptr;
        next = nullptr;
    }
};

void MyAdd(ListNode* headn, ListNode* headm, int n, int m)
{
    int carry = 0;
    int sum = 0;
    ListNode* headsum = new ListNode;
    int minn = min(n, m);
    int maxn = max(n, m);
    int absn = abs(n - m);
    headn = headn->pre;
    headm = headm->pre;

    for(int i = minn; i > 0; i--)
    {
        
        sum = headn->value + headm->value + carry;
        carry = sum / 10;

        ListNode* l = new ListNode(sum % 10);
        l->next = headsum->next;
        headsum->next = l;
        headn = headn->pre;
        headm = headm->pre;
    }
    for (int i = 0; i < absn; ++i)
    {
        if(m>=n)
        {
            headm->value = headm->value + carry;
            carry = headm->value / 10;
            ListNode* temp = new ListNode(headm->value % 10);
            temp->next = headsum->next;
            headsum->next = temp;
            headm = headm->pre;
        }
        else
        {
            headn->value = headn->value + carry;
            carry = headn->value / 10;
            ListNode* temp = new ListNode(headn->value % 10);
            temp->next = headsum->next;
            headsum->next = temp;
            headn = headn->pre;
        }
    }

    if (carry)
    {
        cout << "1";
    }

    headsum = headsum->next;
    for (int i = 0; i < maxn; ++i)
    {
        cout << headsum->value;
        headsum = headsum->next;
    }
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    int temp;
    ListNode* headn = new ListNode;
    ListNode* headm = new ListNode;
    headn->pre = headn;
    headn->next = headn;
    headm->pre = headm;
    headm->next = headm;

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        ListNode* l1 = new ListNode(temp);
        if (headn->next == nullptr)
        {
            headn->pre = l1;
        }
        l1->pre = headn;
        headn->next->pre = l1;
        l1->next = headn->next;
        headn->next = l1;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> temp;
        ListNode* l2 = new ListNode(temp);
        if (headm->next == nullptr)
        {
            headm->pre = l2;
        }
        l2->pre = headm;
        headm->next->pre = l2;
        l2->next = headm->next;
        headm->next = l2;
    }
    MyAdd(headn, headm, n, m);

    return 0;
}
