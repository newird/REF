#include<iostream>
using namespace std;
int WatchMovie(int* a, int pre, int now, int n, int d){
	if(now + 1 > n)
		return 0;
	else if(a[now] < 0)
		return WatchMovie(a, pre, now + 1, n, d);
	else
		return -d * (now - pre) + a[now] + WatchMovie(a, now, now + 1, n, d);
		
}
int main(){
	int n, m, d;
	cin >> n >> m >> d;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int res = 0;
	for(int i = 0; i < n; i++){
		int temp = 0;
		if(a[i] > 0)
			temp = WatchMovie(a, -1, i, n, d);
		res = res < temp ? temp: res;
	}
	cout << res << endl;
	return 0;
}