// 定义链表结点
struct ListNode {
    int val; // 结点的值
    ListNode* next; // 指向下一个结点的指针
    ListNode(int x) : val(x), next(nullptr) {} // 构造函数
};

// 定义链表类
class LinkedList {
private:
    ListNode* head; // 链表的头结点
    int size; // 链表的长度
public:
    // 构造函数，根据给定的数组创建链表
    LinkedList(vector<int>& nums) {
        size = nums.size();
        if (size == 0) { // 如果数组为空，链表也为空
            head = nullptr;
            return;
        }
        head = new ListNode(nums[0]); // 创建头结点
        ListNode* cur = head; // 当前结点指针
        for (int i = 1; i < size; i++) { // 遍历数组，依次创建结点并连接
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }
    }

    // 析构函数，释放链表占用的内存空间
    ~LinkedList() {
        ListNode* cur = head; // 当前结点指针
        while (cur != nullptr) { // 遍历链表，依次删除结点
            ListNode* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    // 返回链表的长度
    int getSize() {
        return size;
    }

    // 返回链表的头结点指针
    ListNode* getHead() {
        return head;
    }

    // 打印链表中的所有元素，用空格分隔
    void printList() {
        ListNode* cur = head; // 当前结点指针
        while (cur != nullptr) { // 遍历链表，依次打印结点的值
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

// 定义加法函数，接受两个链表作为参数，返回一个新的链表，表示两个链表对应位相加的结果
LinkedList* addTwoLists(LinkedList* l1, LinkedList* l2) {
    if (l1 == nullptr) return l2; // 如果第一个链表为空，返回第二个链表
    if (l2 == nullptr) return l1; // 如果第二个链表为空，返回第一个链表
    ListNode* p1 = l1->getHead(); // 指向第一个链表的当前结点的指针
    ListNode* p2 = l2->getHead(); // 指向第二个链表的当前结点的指针
    vector<int> res; // 存储结果的数组
    int carry = 0; // 进位标志
    while (p1 != nullptr || p2 != nullptr || carry != 0) { // 当两个链表都遍历完或者没有进位时停止循环
        int sum = carry; // 当前位的和，初始为进位值
        if (p1 != nullptr) { // 如果第一个链表还有剩余结点，加上其值
            sum += p1->val;
            p1 = p1->next;
        }
        if (p2 != nullptr) { // 如果第二个链表还有剩余结点，加上其值
            sum += p2->val;
            p2 = p2->next;
        }
        res.push_back(sum % 10); // 将当前位的和对10取余，作为结果数组的一个元素
        carry = sum / 10; // 将当前位的和除以10，作为下一位的进位值
    }
    return new LinkedList(res); // 根据结果数组创建一个新的链表并返回
}

// 主函数，用于测试
int main() {
    // 输入两个整数的位数
    int n, m;
    cin >> n >> m;
    // 输入两个整数的各个位的数字
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    // 创建两个链表
    LinkedList* l1 = new LinkedList(a);
    LinkedList* l2 = new LinkedList(b);
    // 调用加法函数，得到结果链表
    LinkedList* l3 = addTwoLists(l1, l2);
    // 打印结果链表
    l3->printList();
    // 释放内存空间
    delete l1;
    delete l2;
    delete l3;
    return 0;
}