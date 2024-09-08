#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb emplace_back
#define mp make_pair
#define rep(i, a, b) for (int i = (a); i < (b); i++)
void no() {cout<<"NO\n";}
void yes() {cout<<"YES\n";}
void yy(bool b){if(b) yes();else no();}
 
int m ,n ;
int a[100005]{} , b[100005]{};
void solve(){
  cin >> m >> n ;
  memset(a, 0 , sizeof a) ;
  memset(b , 0 , sizeof b);
  rep(i , 0 , m) {
    cin >> a[i];
  }
  rep(i , 0 , n ) {
    cin >> b[i];
  }
  int c {} , len = max(m , n ) ;
  rep(i , 0 , len ) {
    int t  = a[i] + b[i] + c ;
    c = t / 10;
    a[i] = t % 10;
  }
  if(c) cout << 1;
  for(int i = len - 1;i >=0 ; --i) {
    cout<< a[i] ;
  }
}

 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t ;
    // cin >> t;
    // while(t -- )
        solve() ;
    return 0;
}
