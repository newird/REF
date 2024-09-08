#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	if(N<1){
		cout<<-1;
	}
	else{
		cout<<N*(N+1)/2;
	}
	return 0;
}