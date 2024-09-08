#include <iostream>
using namespace std;

struct DblNode {
	int data;
	DblNode * lLink, * rLink;
	DblNode(DblNode* left = nullptr, DblNode* right = nullptr)
		:lLink(left), rLink(right) {}
	DblNode(int value, DblNode* left = nullptr, DblNode* right = nullptr)
		: data(value), lLink(left), rLink(right) {}
};

class DblList{
public:
	DblList(int uniqueVal);
	~DblList(){}
	int Length() const;
	bool IsEmpty() { return first->rLink == first; }
	DblNode* getHead() const { return first; }
	void setHead(DblNode* ptr) { first = ptr; }
	DblNode* Search(const int x);
	DblNode* Locate(int i, int d);
	DblNode* first;
	bool Insert(int i, const int x, int d);
	bool Remove(int i, int x, int d);
};

DblList::DblList(int uniqueVal) 
{
	//构造函数：建立双向循环链表的附加头结点，它包含了一个用于某些特定情况的值。
	first = new DblNode(uniqueVal);
	if (first == nullptr) { cerr << "存储分配出错!" << endl; exit(1); }
	first->rLink = first->lLink = first;
};

int DblList::Length() const
{
	//计算带附加头结点的双向循环链表的长度，通过函数返回。
	DblNode* current = first->rLink; 
	int count = 0;

	while (current != first) 
	{
		current = current->rLink; 
		count++; 
	}
	return count;
};

DblNode *DblList::Search(const int x) 
{
	//在带附加头结点的双向循环链表中寻找其值等于x的结点，若找到，则函数返回该结点地址，//否则函数返回NULL
	DblNode* current = first->rLink;
	while (current != first && current->data != x)
	{
		current = current->rLink;
	}
	if (current != first) { return current; }
	else { return nullptr; }
};

DblNode *DblList::Locate(int i, int d)
{
	//在带附加头结点的双向循环链表中按d所指方向寻找第i个结点的地址。若d=0，在前驱方向//寻找第i个结点，若d≠0，在后继方向寻找第i个结点。
	if (first->rLink == first || i == 0) { return first; }
	DblNode* current;
	if (d == 0) { current = first->lLink; } //搜索方向
	else { current = first->rLink; }
	for (int j = 1; j < i; j++)//逐个结点检测
	{
		if (current == first) { break; }//链太短退出搜索
		else if (d == 0) { current = current->lLink; }
		else { current = current->rLink; }
	}
	if (current != first) { return current; }//搜索成功
	else { return nullptr; }//搜索失败
};

bool DblList::Insert(int i, const int x, int d) {
	//建立一个包含有值 x的新结点，并将其按d指定的方向插入到第i个结点之后。
	DblNode* current = Locate(i, d);//查找第i个结点
	if (current == nullptr) { return false; }//i不合理，插入失败
	
	DblNode* newNode = new DblNode(x);
	if (newNode == nullptr) { cerr << "存储分配失败!" << endl; exit(1); }
	
	if (d == 0)//前驱方向插入
	{
		newNode->lLink = current->lLink;
		current->lLink = newNode;
		newNode->lLink->rLink = newNode;
		newNode->rLink = current;
	}
	else//后继方向插入
	{
		newNode->rLink = current->rLink;
		current->rLink = newNode;
		newNode->rLink->lLink = newNode;
		newNode->lLink = current;
	}
	return true;//插入成功
};

bool DblList::Remove(int i, int x, int d) 
{
	//在带附加头结点的双向循环链表中按照d所指方向删除第i个结点。
	DblNode* current = Locate(i, d);//查找第i个结点
	if (current == nullptr) { return false; }//i不合理，删除失败
	current->rLink->lLink = current->lLink;//从 lLink链中摘下
	current->lLink->rLink = current->rLink;//从 rLink链中摘下
	x = current->data; 
	delete current;//删除
	return true;//删除成功
};

int main()
{
	int sizea = 0;
	int sizeb = 0;
	int vala = 0;
	cin >> sizea >> sizeb;
	DblList a(0);
	for (int i = 0; i < sizea; i++)
	{
		cin >> vala;
		if (i == 0) 
		{ 
			a.first->data = vala;
		}
		else 
		{ 
			a.Insert(i - 1, vala, 1); 
		}
	}

	for (int i = 0; i < sizeb; i++)
	{
		cin >> vala;
		if (i > a.Length())
		{
			a.Insert(i-1, vala, 1);
		}
		else
		{
			a.Locate(i, 1)->data = a.Locate(i, 1)->data + vala;
		}
	}

	DblNode* current = a.first->lLink;
	for (int i = 0; i <= a.Length(); i++)
	{
		current = current->rLink;
		if (i == a.Length() && current->data >= 10)
		{
			cout << 1;
			current->data -= 10;
		}
		else if (current->data >= 10)
		{
			current->data -= 10;
			current->rLink->data += 1;
		}
	}
	current = a.first->lLink;
	for (int i = 0; i <= a.Length(); i++)
	{
		cout << current->data;
		current = current->lLink;
	}
	return 0;
}