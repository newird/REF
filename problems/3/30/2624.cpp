#include <iostream>
using namespace std;

int main()
{
	int sizea;
	int sizeb;
	int sizec;
	int res=0;
	cin >> sizea >> sizeb;
	sizec = (sizea > sizeb) ? sizea : sizeb;
	int* a = new int[sizea];
	int* b = new int[sizeb];
	int* c = new int[sizec];

	for (int aa = 0; aa < sizea; aa++){cin >> a[aa];}
	for (int bb = 0; bb < sizeb; bb++){cin >> b[bb];}

	if (sizea > sizeb)
	{
		for (int bbb = 0; bbb < sizeb; bbb++)
		{
			c[bbb] = a[bbb] + b[bbb];
		}
		for (int aaa = sizeb; aaa < sizea; aaa++)
		{
			c[aaa] = a[aaa];
		}
	}

	else if (sizea < sizeb)
	{
		for (int aaa = 0; aaa < sizea; aaa++)
		{
			c[aaa] = a[aaa] + b[aaa];
		}
		for (int bbb = sizea; bbb < sizeb; bbb++)
		{
			c[bbb] = b[bbb];
		}
	}

	else
	{
		for (int ccc = 0; ccc < sizec; ccc++)
		{
			c[ccc] = a[ccc] + b[ccc];
		}
	}

	for (int i = 0; i < sizec; i++)
	{
		res = 10*res + c[sizec-i-1];
	}
	cout << res << endl;
	return 0;
}