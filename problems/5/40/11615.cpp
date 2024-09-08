#include <iostream>
using namespace std;

long long n, m, d;

long long arr[200002];
long long m1[200002];
long long res[200002] = { 0 };

class stack1
{
public:
	long long data;
	stack1* next = nullptr;
	stack1* last = nullptr;
	stack1(long long i) { data = i; };
	friend void insert(long long k);

	friend void pop();
};

stack1* head = nullptr;
stack1* tail = head;

void insert(long long k)
{
	stack1* p = new stack1(k);
	stack1* t1 = tail;
	if (head == nullptr && tail == nullptr)
	{
		head = p;
		tail = p;
	}
	else if (k <= head->data)
	{
		p->next = head;
		head->last = p;
		head = p;
	}
	else if (k >= tail->data)
	{
		tail->next = p;
		p->last = tail;
		tail = p;
	}
	else {
		while (t1->last!=nullptr)
		{
			if (k<t1->data && k>t1->last->data)
			{
				p->last = t1->last;
				p->next = t1;
				t1->last->next = p;
				t1->last = p;
			}
			t1 = t1->last;
		}
		if (t1 == head)
		{
			t1->last = p;
			p->next = t1;
			head = p;
		}
	}
}

void pop()
{
	{
		if (head != nullptr)
		{
			head = head->next;
			head->last = nullptr;
		}
	}
}

int main()
{
	cin >> n >> m >> d;
	long long length = 0;
	int w = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		if (length < m && arr[i]>0)
		{
			insert(arr[i]);
			length++;
			res[i] = res[i - 1] + arr[i];
		}
		else if (length == m && arr[i] > 0 && arr[i] > head->data)
		{
			long long num = head->data;
			pop();
			insert(arr[i]);
			res[i] = res[i - 1] - num + arr[i];
		}
		else {
			res[i] = res[i - 1];
		}
	}
	long long min_m = 0;


	long long max_1 = 0;
	for (int i = 1; i <= n; i++)
	{
		res[i] -= i * d;
		if (res[i] > max_1)
		{
			max_1 = res[i];
		}
	}
	cout << max_1 << endl;
	return 0;
}