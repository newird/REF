#include<iostream>
using namespace std;

//带头结点链式队列
//头尾皆可访问、弹出，尾入
template<class T>
struct node
{
	T ele;
	node* next = NULL;
	node() { }
	node(T e) :ele(e) { }
};

template<class T>
class Queue
{
	node<T>* head = NULL;//头
	node<T>* rear;//尾
public:
	Queue()
	{
		head = new node<T>;
		rear = head;
	}
	~Queue()
	{
		node<T>* q0 = head;
		node<T>* q1 = q0;
		while (q1 != NULL)
		{
			q1 = q1->next;
			delete q0;
			q0 = q1;
		}
	}
	void EnQueue(T x)
	{
		node<T>* q = new node<T>(x);
		rear->next = q;
		rear = q;
	}
	void DeQueueFront()
	{
		if (isEmpty()) return;
		node<T>* q = head;
		head = head->next;
		delete q;
	}
	void DeQueueBack()
	{
		if (isEmpty()) return;
		node<T>* q = rear;
		for (rear = head; rear->next != q; rear = rear->next)
			;
		delete q;
		rear->next = NULL;
	}
	bool isEmpty() const
	{
		return rear == head;
	}
	T getFront() const
	{
		if (isEmpty()) throw("Empty!");
		return head->next->ele;
	}
	T getBack() const
	{
		if (isEmpty()) throw("Empty!");
		return rear->ele;
	}

};

int maxProfit(int days_num, int* incomes)
{
	Queue<int> q;//保证递增
	int max_in = 0;
	for (int i = 0; i < days_num; i++)
	{
		while (!q.isEmpty() && q.getBack() >= incomes[i])
		{
			int current_in = q.getBack() - q.getFront();
			max_in = max_in < current_in ? current_in : max_in;
			q.DeQueueBack();
		}
		q.EnQueue(incomes[i]);
	}
	int current_in = q.getBack() - q.getFront();
	max_in = max_in < current_in ? current_in : max_in;
	return max_in;
}

int main()
{
	int n;
	cin >> n;
	int* P = new int[n];
	for (int i = 0; i < n; i++)
		cin >> P[i];
	cout << maxProfit(n, P);
	delete[] P;
	return 0;
}