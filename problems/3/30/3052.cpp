#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main()
{
	int sizea;
	int sizeb;
	int res=0;
	cin >> sizea >> sizeb;
	string a = "";
	string b = "";
	string va = "";
	string vb = "";
	int iadder=0;
	for (int i = 0; i < sizea; i++)
	{
		cin >> iadder;
		a.append(to_string(iadder));
	}
	for (int i = 0; i < sizeb; i++)
	{
		cin >> iadder;
		b.append(to_string(iadder));
	}
	//reverse(a.begin(), a.end());
	//reverse(b.begin(), b.end());
	for (int i = 0; i < sizea; i++)
	{
		va.append(",");
	}
	for (int i = 0; i < sizeb; i++)
	{
		vb.append(",");
	}
	for (int i = 0; i < sizea; i++)
	{
		va[i] = a[sizea - i - 1];
	}
	for (int i = 0; i < sizeb; i++)
	{
		vb[i] = b[sizeb - i - 1];
	}

	res = stoi(va)+stoi(vb);
	cout << res;
	return 0;
}