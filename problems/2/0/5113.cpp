#include<iostream>
#include<stack>
#include<vector>
#include<queue>

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
    int left = 0, right = n - 1;
    while(left < right){
        ans = max(ans, nums[right] - nums[left]);
        if(nums[left + 1] <= nums[left]){
            left++;
        }else{
            right--;
        }
    }
    cout << ans;
    return 0;
}

int max(int a, int b){
    if(a >= b){
        return a;
    }
    return b;
}