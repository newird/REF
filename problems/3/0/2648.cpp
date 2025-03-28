#include<iostream>
#include<queue>
#include<vector>
#include <string>

using namespace std;

int main(){
    int n,m;
    cin >> n;
    cin >> m;
    vector<int> Num_m;
    vector<int> Num_n;
    vector<char> ans;
    int scan;
    int m_head,n_head;
    int CF = 0;
    int res;
    for(int i = 0; i < n; i++){
        cin >> scan;
        Num_n.push_back(scan);
    }
    for(int i = 0; i < m; i++){
        cin >> scan;
        Num_m.push_back(scan);
    }
    while(!(Num_m.empty() || Num_n.empty())){
        m_head = Num_m.back();
        n_head = Num_n.back();
        Num_m.pop_back();
        Num_n.pop_back();
        if(m_head + n_head + CF >= 10){
            res = m_head + n_head + CF - 10;
            CF = 1;
        }else{
            res = m_head + n_head + CF;
            CF = 0;
        }
        ans.insert(ans.begin(), res + '0');
    }
    int size = ans.size();
    while(!Num_m.empty()){
        m_head = Num_m.back();
        Num_m.pop_back();
        if(m_head + CF >= 10){
            res = m_head + CF - 10;
            CF = 1;
        }else{
            res = m_head + CF;
            CF = 0;
        }
        ans.insert(ans.begin(), res + '0');
    }
    while(!Num_n.empty()){
        n_head = Num_n.back();
        Num_n.pop_back();
        if(n_head + CF >= 10){
            res = n_head + CF - 10;
            CF = 1;
        }else{
            res = n_head + CF;
            CF = 0;
        }
        ans.insert(ans.begin(), res + '0');
    }
    if(CF == 1){
        ans.insert(ans.begin(), '1');
        CF = 0;
    }
    size = ans.size();
    for(int i = 0; i < size; i++){
        cout << ans.back();
        ans.pop_back();
    }
    return 0;
}