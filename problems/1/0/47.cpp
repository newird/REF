#include <iostream>
#include <cstdio>
using namespace std;
int n;
int main(){
	cin>>n;
	if(n<1) cout<<-1;
	else cout<<(1+n)*n/2;
}
