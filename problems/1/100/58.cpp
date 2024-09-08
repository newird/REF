#include <iostream>
#include <cstdio>
using namespace std;
long long n;
int main(){
	cin>>n;
	if(n<1) cout<<-1;
	else cout<<(1+n)*n/2;
}
