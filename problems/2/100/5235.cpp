#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<stack>
using namespace std;
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include<cstring>
#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include<map>
#include<numeric>
#include <stdint.h>
#include<stack>

using namespace std;
struct mix {
	int num;
	int no;
};
//bool cmp(mix a, mix b)
//{
//	
//	return a.num > b.num;
//}
int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	stack<int> a;//a的栈顶最低，
	int res = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (i == 0) {
			a.push(temp);
		}
		else {
			int restmp = temp - a.top();
			if (restmp > res)res = restmp;
			if (temp < a.top() ){
				a.push(temp);
			}
			



		}
		
	}
	
	cout << res;


}
