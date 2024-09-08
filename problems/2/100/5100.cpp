#include<cstdio>
#include<algorithm>
using namespace std;
int p[100005],a[100005],b[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	a[0]=10005;
	for (int i=1;i<=n;i++) a[i]=min(a[i-1],p[i]);
	for (int i=n;i;i--) b[i]=max(b[i+1],p[i]);
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,b[i+1]-a[i+1]);
	printf("%d",ans);
	return 0;
}