#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	long long N;
	cin>>N;
	if(N<1){
		cout<<-1;
	}else{
		cout<<(1+N)*N/2;
	}
	return 0;
}