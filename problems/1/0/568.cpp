include<iostream>
using namespace std;
int main(void) {
	long long int n;
	long long Sn = 0;

	cin >> n;
	if(n<1){
		cout << "-1";
		return 0;
}
	Sn = ((1 + n) * n) / 2;
	cout << Sn;

return 0;
}