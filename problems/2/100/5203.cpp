#include<iostream>
#include<stack>
#include<vector>
#include<deque>

using namespace std;

int max(int a, int b);
int main(){
    int n;
    cin >> n;
    int ans = 0;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int min = 100000;

    for(int i = 0; i < n; i++){
        if(min == 100000){
            min = nums[i];
        }else{
            if(nums[i] > min){
                ans = max(ans, nums[i] - min);
            }else{
                min = nums[i];
            }
        }
    }

    cout << ans << endl;
    return 0;
}

int max(int a, int b){
    if(a >= b){
        return a;
    }
    return b;
}