#include <iostream>
#include <bits/stdc++.h>

using namespace std; 




int main() {
	
	int n;
	cin >> n;
	
	vector<int> v;
	
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	} 
	
	long long max = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			long long sum = 0;
			if(v[j] <= v[i]) {
				continue;
			} else {
				sum += v[j] - v[i];
			}
			if(max < sum) {
				max = sum;
			}
		}
	}
	
	cout << max;

} 