#include<iostream>
#include<cstdio>

using namespace std;

int read() {
	int x = 0, f = 1; char ch;
	ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') f = -f; ch = getchar();}
	while(ch <= '9' && ch >= '0') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

int n, m, a, tot, w[200005];

long long d, sum, ans;

int top() {
	return w[1];
}

void modify(int x) {
    if(x == 1 || w[x] > w[x / 2]) return;
    swap(w[x], w[x / 2]);
    modify(x / 2);
}

void push(int x) {
    w[++tot] = x;
    modify(tot);
}

void repair(int x) {
    if(x * 2 > tot) return;
    int tar = x * 2;
    if(x * 2 + 1 <= tot) tar = w[x * 2] < w[x * 2 + 1] ? x * 2 : x * 2 + 1;
    if(w[x] < w[tar]) return;
    swap(w[x], w[tar]);
    repair(tar);
}

void pop() {
    swap(w[1], w[tot--]);
    repair(1);
}

int main() {
	n = read();
	m = read();
	d = read();
	for(int i = 1; i <= n; i++) {
		a = read();
		if(a <= 0) continue;
		if(tot < m) {
			sum += a;
			push(a);
		}
		else if(a > top()) {
			sum -= top();
			pop();
			sum += a;
			push(a);
		}
		ans = max(ans, sum - d * i);
	}
	printf("%lld", ans);
	return 0;
}
