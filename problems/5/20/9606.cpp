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
	int c = 0;
	int r = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	A* head = NULL;
	for (int i = 0; i < n; i++)
	{
		if (x[i] > 0)
		{
			
			int q = 0;
			A* p = head;
			if (c == m)
			{
				if (head!=NULL && x[i] <= head->a)
					;
				else
				{
					A* s = NULL;

					while (p != NULL && x[i] > p->a)
					{
						s = p;
						p = p->next;
					}
					if (p == NULL && s!=NULL)
					{
						p = new A;
						p->a = x[i];
						p->next = NULL;
						s->next = p;
					}
					else
					{
						if (s != NULL)
						{
							s->next = new A;
							s->next->a = x[i];
							s->next->next = p;
						}

					}if(head!=NULL)
						r = r - head->a + x[i];
					head = head->next;
					q = r - (i + 1) * d;
					k = k > q ? k : q;
					cout << k << endl;
				}
			}
			else
			{
				if (head == NULL)
				{
					head = new A;
					head->a = x[i];
					head->next = NULL;
					c++;
					r += x[i];
					q = r - (i + 1) * d;
					k = k > q ? k : q; 
					
				}
				else
				{
					A* s = head;
					c++;
					
					while (p != NULL && x[i] > p->a)
					{
						s = p;
						p = p->next;
						
					}
					if (p == NULL)
					{
						p = new A;
						p->a = x[i];
						p->next = NULL;
						s->next = p;
					}
					else
					{
						s->next = new A;
						s->next->a = x[i];
						s->next->next = p;

					}
					r += x[i];
					q = r - (i + 1) * d;
					k = k > q ? k : q;
					
				}
			}

		}
	}cout << k << endl;
}