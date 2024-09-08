#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
	int n,m,x;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) 
	{
		scanf("%d",&x);
		a[i]+=x;
		if (a[i]>9) a[i]-=10,a[i+1]++;
	}
	for (int i=m;i<=n;i++) if (a[i]>9) a[i]-=10,a[i+1]++;
	x=max(n,m);
	if (a[x+1]) x++;
	while (x)
	{
		printf("%d",a[x]);
		x--;
	}
	return 0;
}