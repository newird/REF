#include <iostream>
#include <algorithm> 
using namespace std;
long long n, m, d;
struct movie{
	long long val, pos;
}a[200005]; 
bool cmp(movie x, movie y){
	if(x.val > y.val) return true;
	else if(x.val == y.val && x.pos < y.pos) return true;
	else return false;
}
long long sum, ans;
int main(){
	scanf("%lld%lld%lld", &n, &m, &d);
	for(long long i=1; i<=n; i++) {
		scanf("%lld", &a[i].val);
		a[i].val -= d*i;
		a[i].pos = i;
	}
	sort(a+1, a+n+1, cmp);
	long long maxpos = 0;
	for(long long i=1; i<=m; i++){
		maxpos = max(maxpos, a[i].pos);
		sum += a[i].val + a[i].pos * d;
		ans = max(ans, sum - d * maxpos);
	}
	printf("%lld", ans); 
}
