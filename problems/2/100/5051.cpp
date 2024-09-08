#include <bits/stdc++.h>
using namespace std;

int a[100001];
int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int ans = 0, cur = a[0];
	for (int i=1; i<n; i++) {
		if (a[i] < cur)
			cur = a[i];
		else
			ans = max(ans, a[i] - cur);
	}
	cout << ans << endl;
	return 0;
}
