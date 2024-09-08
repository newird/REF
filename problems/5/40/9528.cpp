#include <iostream>
#include <algorithm> 
using namespace std;
int n, m, d, num, maxpos;
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
		if(a[i].val > 0)  num++;
		a[i].pos = i;
	}
	
	sort(a+1, a+n+1, cmp);
	for(int i=1; i<=max(m, num); i++){
		maxpos = max(a[i].pos, maxpos);
		sum += a[i].val;
		ans = max(ans, sum - d * maxpos);
	}
	printf("%lld", ans); 
}
