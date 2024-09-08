#include <iostream>

using namespace std;

int main(){
	long long n;
	cin >> n;
	
	long long sum;
	
	if(n < 1){
		return -1;
	} 
	for(int i = 1; i <= n; i++){
		sum += i;
	}
	cout << sum;
}