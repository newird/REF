#include<iostream>

int f(int n) {
 if(n == 0 ) {
return 0 ;
}
return n + f(n-1) ;
}
int main(){
int x {} ;
for(int i = 0 ; i < 10000 ; ++i ){
for(int j = 0 ; j < 10000; ++i ){
 ++x ;
}
}
int n ;
std::cin>> n ;
std::cout<<  f(n) ;
return 0 ;
}