#include<iostream>
#include<stack>
using namespace std;


/*int main() {
	int n;
	cin >> n;
	int head = 0, tail = 0;
	int a[100005] = { 0 };
	int mymax = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int pro = a[j] - a[i];
			if (pro > mymax)	mymax = pro;
		}
	}
	cout << mymax;


	return 0;
}*/

int lmax(int a, int b) {
	return a > b ? a : b;
}


int main() {
	stack<int>q;
	int n;
	cin >> n;
	int mymax=0;
	int b = 0;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;

		if (q.empty()) { 
			q.push(m);
			b = m;
		}
		else {
			int t = q.top();
			q.pop();
			if (q.empty()) {
				if (t > m) {
					q.push(m);
					b = m;
				}
				else {
					q.push(t);
					q.push(m);
					b = t;
				}
			}
			else {
				if (t > m) {
					mymax = lmax(t - b, mymax);
					t = q.top();
					while (t > m) {
						q.pop();
						t = q.top();
					}
					q.push(m);
				}
				else {
					q.push(t);
					q.push(m);
				}
			}
		}
	}
	int t = q.top();
	mymax = lmax(mymax, t-b);
	cout << mymax;

	return 0;
}