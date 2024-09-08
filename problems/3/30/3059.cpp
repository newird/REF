#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main()
{
	string a = "";
	string b="";
	int sizea;
	int sizeb;
	int res=0;
	//int iadder;
	string sadder;
	cin >> sizea >> sizeb;
	for (int i = 0; i < sizea; i++)
	{
		cin >> sadder;
		a.append(sadder);
	}
	for (int i = 0; i < sizeb; i++)
	{
		cin >> sadder;
		b.append(sadder);
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	res = stoi(a)+ stoi(b);
	cout << res;
	return 0;
}