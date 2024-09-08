using namespace std;
#include <iostream>


void search(int a[], int pos[], int id, int len, int left, int d, long long sum, long long& max) {
	if (left == 0 || id == len) return;
	else {
		search(a, pos, id + 1, len, left, d, sum, max);
		//if ([a[id] > 0) 
		sum += (long long)a[id];
		long long temp = sum - (long long)d * (pos[id] + 1);
		if (temp > max) max = temp;
		search(a, pos, id + 1, len, left - 1, d, sum, max);
	}
	return;
}

int main() {
	long long max = 0;
	int n, m, d;
	cin >> n >> m >> d;
	int* a = new int[n];
	int* pos = new int[n];
	int in;	
	int top = 0;
	for (int i = 0; i < n; i++) {
		cin >> in;
		if (in > 0) {
			a[top] = in;
			pos[top] = i;
			top++;
		}
	}

	search(a, pos, 0, top, m, d, 0, max);
	cout << max << endl;
	return 0;
}