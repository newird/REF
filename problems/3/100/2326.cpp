#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) begin(x), end(x)

using LL = long long;
using PII = pair<int, int>;
using PLI = pair<LL, int>;
using ULL = unsigned long long;

const int inf = 2000000000;
const int mod = 998244353;

const array<int, 2> dir[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void solve(){
    
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(m), ans;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    for(int j = 0; j < m; ++j){
        cin >> b[j];
    }
    
    int carry = 0;
    for(int i = 0, j = 0; i < n || j < m; ++i, ++j){
        int x = carry;
        if(i < n) x += a[i];
        if(j < m) x += b[j];
        ans.emplace_back(x % 10);
        carry = x / 10;
    }
    
    if(carry)
        ans.emplace_back(1);
    reverse(all(ans));
    
    for(int x : ans){
        cout << x;
    }
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
    // int t;
    // for(cin >> t; t; --t){
        // solve();
    // }
    
    solve();

    return 0;
}
