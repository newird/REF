#include<iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int* x = (int*)malloc(sizeof(int) * (max(a, b) + 1));
	int* y = (int*)malloc(sizeof(int) * (max(a, b) + 1));
	int* r = (int*)malloc(sizeof(int) * (max(a, b) + 1));
	for (int i = 0; i <= max(a, b); i++) { x[i] = 0; }
	for (int i = 0; i <= max(a, b); i++) { y[i] = 0; }
	for (int i = 0; i < a; i++) { cin >> x[i]; }
	for (int i = 0; i < b; i++) { cin >> y[i]; }
	for (int i = 0; i <= max(a, b); i++) { r[i] = 0; }
	for (int i = 0; i < max(a, b); i++) { 
		r[i] = x[i] + y[i];
		if (r[i] >= 10) { r[i] -= 10; r[i + 1]++; }
	}
	for (int i = max(a, b); i >=0 ; i--) { if (i != max(a, b) || r[i] != 0) { cout << r[i]; } }
	return 0;
}