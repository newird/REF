#include <iostream>

using namespace std;

int main(){
	
	int n, m;
	
	cin >> n >> m;
	
	int a[100001];
	
	
	
	for(int i = 0; i < n; i++){
		a[i] = 0;
	}
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i < m; i++){
		int b;
		cin >> b;
		a[i] += b;
	}
	
	for(int i = 0; i < max(n, m); i++){
		if(a[i] >= 10){
			a[i] = a[i] % 10;
			a[i + 1]++;
		} 
	}
	
	
	if(a[max(n, m)] > 0){
		cout << a[max(n, m)];
	}
	for(int i = max(n, m) - 1; i >= 0; i--){
		cout << a[i];
	}
	 
}



	
	



