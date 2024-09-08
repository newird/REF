#include <iostream>
using namespace std;
int n, p[100005],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d", &p[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans = max(ans, p[j]-p[i]);
		}
	}
	cout<<ans;
}
