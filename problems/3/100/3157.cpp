#include <iostream>
using namespace std;

int main() {
	int n = 0, m = 0, max = 0;;
	cin >> n >> m;
	max = n > m  ? n  : m;
	int* a = new int[max];
	int* b = new int[max];
	//int nmax = max + 1;
	int* res = new int[max];

	for (int i = 0;i < max;i++) {
		a[i] = -1;
		b[i] = -1;
	}

	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for (int i = 0;i < m;i++) {
		cin >> b[i];
	}

	int cf = 0;
	for (int i = 0;i < max;i++) {
		if (a[i] == -1)
			a[i] = 0;
		if (b[i] == -1)
			b[i] = 0;


		res[i] = a[i] + b[i] + cf;
		if (res[i] >= 10) {
			res[i] = res[i]-10;
			cf = 1;
		}
		else cf = 0;

		
	}
	if (cf == 1)
		cout << "1";
      for (int i = max-1;i >= 0;i--) {
			cout << res[i] ;
		}
	  
       cout << endl;
		return 0;
	}