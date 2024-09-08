#include<iostream>

using namespace std;

typedef struct stack {
	char data[100];
	int top;
	int bottom;
};

//创建
stack* stackcreate()
{
	stack* p = new stack;
	if (p) {
		p->bottom = p->top = 0;
		return p;
	}
}

//入栈
void stackinput(stack* p, char ch)
{
	p->data[p->top] = ch;
	p->top++;
}

//出栈
int stackoutput(stack* p)
{
	if (p->top != p->bottom) {
		int ch = p->data[p->top - 1];
		p->top--;
		return ch;
	}
}

//栈的遍历
void stackprint(stack* p)
{
	while (p->top != p->bottom) {
		cout << p->data[p->top - 1];
		p->top--;
	}
}

//判断栈是否为空
int stackempty(stack* p)
{
	if (p->top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}
//释放指针
void stackfree(stack* p)
{
	free(p);
}

int main()
{
	int n;
	cin >> n;

	int* P = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> P[i];
	}

	stack* q;
	q = stackcreate();
	int biggest = 0;

	for (int i = 0; i < n; i++)
	{
		if (stackempty(q)) {  //里面空
			stackinput(q, P[i]);
		}
		else {
			int output = stackoutput(q);
			if (P[i] < output) {
				stackinput(q, P[i]);
			}
			else if(P[i] > output){
				int minus = P[i] - output;
				stackinput(q, output);

				if (minus > biggest) {
					biggest = minus;
				}
			}
			else {                           //等于的情况
				stackinput(q, P[i]);
			}
		}
	}

	cout << biggest;
	return 0;
}