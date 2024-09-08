#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	int sum;
	
	if(n < 1){
		cout << -1;
		return 0;
	} 
	for(int i = 1; i <= n; i++){
		sum += i;
	}
	cout << sum;
}