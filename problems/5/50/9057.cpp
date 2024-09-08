#include <iostream>
using namespace std;

void Adjust(int a[][2], int k, int n) {
	while (2 * k + 2 <= n) {
		int i;
		if (2 * k + 2 < n) {
			i = (a[2 * k + 1][0] > a[2 * k + 2][0]) ? (2 * k + 2) : (2 * k + 1);
			if (a[k][0] > a[i][0]) {
				int tmp = a[k][0]; a[k][0] = a[i][0]; a[i][0] = tmp;
				tmp = a[k][1]; a[k][1] = a[i][1]; a[i][1] = tmp;
			}
			k = i;
		}
		else if ((2 * k + 2 == n) && (a[k][0] > a[n - 1][0])) {
			int tmp = a[k][0]; a[k][0] = a[i][0]; a[i][0] = tmp;
			tmp = a[k][1]; a[k][1] = a[i][1]; a[i][1] = tmp;
			k = n - 1;
		}
		else { break; }
	}
}

int main() {
	int n, m, d, Max, size = 0, sum = 0, i = 0;
	cin >> n >> m >> d;
	Max = -1;
	int a[200000][2]; int b[200000];
	for (int i = 0; i < n; i++) { cin >> b[i]; }
	for (; i < n; i++) {
		if ((size < m) && (b[i] > d * (i - Max))) {
			a[size][0] = b[i]; a[size][1] = i;
			for (int j = Max + 1; j < i; j++) {
				if (size == m - 1) { break; }
				if (b[j] > 0) { size++; a[size][0] = b[j]; a[size][1] = j; }
			}
			Max = i; size++;
		}
		else if (size == m) { break; }
	}
	for (int j = m - 1; j < 0; j--) { Adjust(a, j, size); }
	for (; i < n; i++) {
		if (b[i] > a[0][0] + d * (i - Max)) {
			a[0][0] = b[i]; a[0][1] = i; Adjust(a, 0, size);
			for (int j = Max + 1; j < i; j++) {
				if(b[j]>a[0][0]){
					a[0][0] = b[j]; a[0][1] = j; Adjust(a, 0, size);
				}
			}
			Max = i; 
		}
	}
	for (int i = 0; i < size; i++) { sum += a[i][0]; }
	sum -= d * (Max + 1);
	cout << sum;
	return 0;
}