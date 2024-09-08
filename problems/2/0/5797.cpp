#include<iostream>
using namespace std;

int f(int a[], int len){
	int res = 0;
	int t = len/2;
	int min = a[0];
	for(int i = 1; i<= t; i++)
		if(min>a[i])
			min = a[i];
	int max = a[t];
	for(int i = t; i< len; i++)
		if(a[i]>max)
			max=a[i];
	res = max > min? max-min:0;
	int temp_l=f(a,t);
	int temp_r=f(a,len-t);
	res = temp_1>res?temp_l:res;
	res = temp_r>res?temp_r:res;
	return res;
}
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max = 0;
	max=f(a,n);
	cout << max << endl;
	return 0;
}