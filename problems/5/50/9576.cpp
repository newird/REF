#include<iostream>
using namespace std;
struct A
{
	int a;
	A* next;
};
int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	int* x = new int[n];
	
	
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	A* head = NULL;
	for (int i = 0; i < n; i++)
	{
		if (x[i] > 0)
		{
			int c = 0;
			int q = 0;
			A* p = head;
			while (p != NULL && c <= m - 1)
			{
				q += p->a;
				p = p->next;
				c++;
			}q = q + x[i] - (i + 1) * d;
			k = k > q ? k : q;
			
			p = head;
			A* u = NULL;
			while (p != NULL && x[i] < p->a)
			{
				u = p;
				p = p->next;
			}
			if (head == NULL)
			{
				head = new A;
				head->a = x[i];
				head->next = NULL;
			}
			else if (p == NULL)
			{
				p = new A;
				p->a = x[i];
				p->next = NULL;
				if (u != NULL)
				{
					u->next = p;
				}
			}
			else
			{
				A* s = new A;
				s->a = x[i];
				s->next = p->next;
				p->next = s;
				s->a = p->a;
				p->a = x[i];
			}
		}
	}cout << k << endl;
}