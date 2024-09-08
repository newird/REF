#include<iostream>
using namespace std;
int WatchMovie(int* a, int pre, int now, int n, int d){
	int sum = 0;
	if(now + 1 > n)
		sum = 0;
	else if(a[now] < 0)
		sum = WatchMovie(a, pre, now + 1, n, d);
	else
		sum = -d * (now - pre) + a[now] + WatchMovie(a, now, now + 1, n, d);
	return sum;
		
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