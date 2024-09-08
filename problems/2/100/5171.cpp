#include<iostream>
using namespace std;
struct data{
    int i;
    int pos;
    data(int a,int b):i(a),pos(b){};
};
int main(){
    int temp,n,earn=0;
    data min(10000,-1),max(0,-1);
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp>max.i){
            max=data(temp,i);
        }
        if(temp<min.i){
            min=data(temp,i);
            max=data(0,-1);
        }
        if(min.pos<max.pos&&max.i-min.i>earn){
            earn=max.i-min.i;
        }
    }
    cout<<earn;
    return 0;
}