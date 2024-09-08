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
int main() {
	int n;
	cin >> n;
	int* p = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	int res = 0;
	for (int i = 0; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (p[j] - p[i] > res) {
				res = p[j] - p[i];
			}
		}
	}
	cout << res;




}
