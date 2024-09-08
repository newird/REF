#include <iostream>
#include <algorithm> 
using namespace std;
int n, m, d;
struct movie{
	long long val;
	int pos;
}a[200005]; 
bool cmp(movie x, movie y){
	if(x.val > y.val) return true;
	else if(x.val == y.val && x.pos < y.pos) return true;
	else return false;
}
long long sum, ans;
int main(){
	scanf("%d%d%d", &n, &m, &d);
	for(int i=1; i<=n; i++) {
		scanf("%lld", &a[i].val);
		a[i].pos = i;
	}
	sort(a+1, a+n+1, cmp);
	int maxpos = 0;
	for(int i=1; i<=m; i++){
		maxpos = max(maxpos, a[i].pos);
		sum += a[i].val;
		ans = max(ans, sum - d * maxpos);
	}
	printf("%lld", ans); 
}
