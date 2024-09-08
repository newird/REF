#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main()
{
	int sizea;
	int sizeb;
	int sizeaa=0;
	int sizebb=0;
	int res=0;
	cin >> sizea >> sizeb;
	string a = "";
	string b = "";
	int iadder=0;
	for (int i = 0; i < sizea; i++)
	{
		cin >> iadder;
		//a.append(to_string(iadder));
		a = to_string(iadder) + a;
	}
	for (int i = 0; i < sizeb; i++)
	{
		cin >> iadder;
		b = to_string(iadder) + b;
	}
	//reverse(a.begin(), a.end());
	//reverse(b.begin(), b.end());

	res = stoi(a)+stoi(b);
	cout << res;
	return 0;
}