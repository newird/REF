#include<iostream>
#include<limits.h>
using namespace std;
int main() {
	int n, m, d;
	cin >> n >> m >> d;
	int *src=new int[n];
	int* flag = new int[n];
	int* opr = new int[n];
	int back = 0;//记录back到了那个位置
	
	for (int i = 0; i < n; i++) {
		cin >> src[i];
		flag[i] = 1;//1表示还没取走
		opr[i] = src[i] - d * (i + 1);

	}

	int i = 0;
	int res = 0;
	while (i < m) {
		int newnum = INT_MIN;//本轮新的待取数
		int newno = 0;
		for (int j = 0; j < n; j++) {
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
			if (newno > back) {
				for (int q = back; q < newno-1; q++) {
					opr[q] = src[q];
				}
				for (int q = newno; q < n; q++) {
					opr[q] = src[q]-d * (q-newno);
				}
				back = newno + 1;
			}
		}

		i++;



	}
	cout << res;


}