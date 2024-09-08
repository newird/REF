#include<iostream>
int main(){
    long long int n; 
    std::cin>>n;
    if(n<1){std::cout<<-1<<std::endl;}
    else{std::cout<<(n+1)*n/2<<std::endl;}
}