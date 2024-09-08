#include<cstdio>
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	if (n<1) printf("-1");
	else printf("%lld",(n*(n-1))>>1);
}