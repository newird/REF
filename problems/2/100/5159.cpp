#include <iostream>
using namespace std;
int n, p[100005], m[100005], ans;
//m[i]之后天中的最高价格 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d", &p[i]);
		m[i] = p[i];
	}
	for(int i=n-1;i>=1;i--){
		m[i] = max(m[i+1], m[i]);
	} 
	for(int i=1;i<=n-1;i++){
		ans = max(ans, m[i+1] - p[i]);
	}
	cout<<ans;
}
