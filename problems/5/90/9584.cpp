#include <iostream>
using namespace std;

long long n, m, d;

long long arr[200002];
long long m1[200002];
long long res[200002]={0};

class stack1
{
public:
	long long data;
	stack1* next = nullptr;
	stack1(long long i) { data = i; };
	void insert(long long k,stack1*& h)
	{
		stack1 *p=new stack1(k);
		stack1* h1 = h;
		if (h == nullptr)
		{
			h = p;
		}
		else {
			if (h->data >= k)
			{
				p->next = h;
				h = p;
			}
			else {
				while (h1->next != nullptr)
				{
					if (h1->data < k && h1->next->data >= k)
					{
						p->next = h1->next;
						h1->next = p;
						break;
					}
					h1 = h1->next;
				}
				if (h1->next = nullptr)
				{
					h1->next = p;
				}
			}
		}

	};

	void pop(stack1*& h)
	{
		if (h != nullptr)
		{
			h = h->next;
		}
	}
};

stack1* head = nullptr;

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
			head->insert(arr[i], head);
			length++;
			res[i] = res[i - 1] + arr[i];
		}
		else if (length == m && arr[i] > 0 && arr[i] > head->data)
		{
			long long num = head->data;
			head->pop(head);
			head->insert(arr[i], head);
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