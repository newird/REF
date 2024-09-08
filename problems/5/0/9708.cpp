#include<iostream>
#include<limits.h>
using namespace std;
int main() {
	long long int n, m;
	long long int d;
	cin >> n >> m >> d;
	long long int* src = new long long int[n];
	long long int* flag = new long long int[n];
	long long int* opr = new long long int[n];
	long long int back = 0;//记录back到了那个位置

	for (long long int i = 0; i < n; i++) {
		cin >> src[i];
		flag[i] = 1;//1表示还没取走
		opr[i] = src[i] - d * (i + 1);

	}

	long long int i = 0;
	long long int res = 0;
	long long int minn = m < n ? m : n;
	while (i < minn) {
		long long int newnum = INT_MIN;//本轮新的待取数
		long long int newno = 0;
		for (long long int j = 0; j < n; j++) {
			if (flag[j] == 1 && opr[j] > newnum) {
				newnum = opr[j];
				newno = j;
			}
		}
		//cout << newnum << "YYYYYYYYYYY" << newno<<endl;
		if (newnum <= 0)break;
		else {
			flag[newno] = 0;//取走
			res += newnum;
			if (newno > =back) {
				for (long long int q = back; q < newno ; q++) {
					opr[q] = src[q];
				}
				for (long long int q = newno; q < n; q++) {
					opr[q] = src[q] - d * (q - newno);
				}
				back = newno + 1;
			}
		}

		i++;



	}
	cout << res;


}