#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,p=0,max=0;
    cin >> n;
    if(n==1){cout << 0;return 0;}
    int* P = new int[n];
    for(int i=0;i<n;i++){
        cin >> P[i];
    }
    for(int j=0;j<n;j++){
        int maybe=0;
        for(int k=j;k<n;k++){
            maybe=P[k]-P[j]>maybe?P[k]-P[j]:maybe;
        }
        max=maybe>max?maybe:max;
    }
    cout << max;
}