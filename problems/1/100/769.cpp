#include <iostream>

using namespace std;

int main(){
	long n;
	cin >> n;
	
	long sum;
	
	if(n < 1){
		cout << -1;
	} else {
		for(int i = 1; i <= n; i++){
		    sum += i;
	    }
	    cout << sum;
	} 
	
}