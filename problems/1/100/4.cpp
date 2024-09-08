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
    
    int n;
    cin >> n;
    
    if(n < 1){
        cout << -1 << endl;
        return;
    }
    
    LL sum = 0;
    for(int i = 1; i <= n; ++i){
        sum += i;
    }
    cout << sum << endl;
    
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
