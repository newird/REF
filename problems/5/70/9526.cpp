#include <iostream>
#define inf 0x7fffffffffffffff 
using namespace std;
int n, m, d, t;
long long q[200005], sum, ans;

void insert(long long x){
	if(t<m){
		q[++t] = x;
		sum += x;
		int i = t;
		while(q[i-1]<x){
			swap(q[i-1], q[i]);
			i--;
		}
	}
	else if(t == m && x > q[t]){
		sum = sum - q[t] + x;
		q[t] = x;
		int i = t;
		while(q[i-1]<x){
			swap(q[i-1], q[i]);
			i--;
		}
	}
}
void print(){
	for(int i=1;i<=t;i++) printf("%lld ", q[i]);
	printf("\n");
}

int main(){
	scanf("%d%d%d", &n, &m, &d);
	
	q[0] = inf;
	long long x;
	for(int i=1; i<=n; i++) {
		scanf("%lld", &x);
		if(x > 0){
			insert(x);
			ans = max(ans, sum - d*i);
		}
		//print();
	}
	
	printf("%lld", ans); 
}

//gap只与最后一次看电影的时间有关
//前面的只需选择最大的a[i]即可
//需要找到前k个里面最大的m个 (m<=k<=n) 
