#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int buy_now=INT32_MAX,sell_now=0,better_buy=0,better_sell=0;
    int n,p;
    cin >> n;

    if(n==1){cout << 0;return 0;}

    int best=0;


    for(int i=0;i<n;i++){
        cin >> p;
        if(p<buy_now){
            buy_now=p;
            better_sell=0;
            sell_now=p;
        }
        if(p>sell_now){
            better_sell=1;
            sell_now=p;
        }
        if(better_sell==1){
            best=sell_now-buy_now>best?sell_now-buy_now:best;
        }
        
    }
    cout << best;
}