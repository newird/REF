#include<iostream>
using namespace std;
int main(){
    int n;
    int p[100010];
    cin>>n;
    if (n == 1) {cout<<0; return 0;}
    for (int i = 1; i <= n; i++) cin>>p[i];
    int max = p[2], min = p[1];
    int maxi = 2, mini = 1;
    int ans = 0;
    if (max > min) ans = max - min;
    for (int i = 2; i <= n - 1; i++){
        if (p[i + 1] > max) {
            max = p[i + 1]; maxi = i;
        }
        if (p[i] < min) {
            min = p[i]; mini = i;
        }
        if (maxi <= mini){
            maxi = mini + 1;
            max = p[maxi];
        }
        if (max - min > ans) ans = max - min; 
    }
    cout<<ans;
    return 0;
}