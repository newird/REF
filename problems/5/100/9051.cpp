#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,d;
int a[200005];
class heap{//小根堆
    
    int siz,maxn,sum;
    int *v;
public:
    heap(int x){
        maxn=x;
        v=new int[maxn];
        siz=0;
        sum=0;
    }
    void insert(int val){
        sum+=val;
        v[siz++]=val;
        int cur=siz-1,fa=(cur-1)/2;
        while(cur&&v[cur]<v[fa]){
            swap(v[cur],v[fa]);
            cur=fa;
            fa=(cur-1)/2;
        }
    }
    void pop(){
        sum-=v[0];
        v[0]=v[siz-1];
        siz--;
        int cur=0,lson=2*cur+1,rson=2*cur+2;
        while(1){
            int temp=cur;
            if(lson<siz&&v[cur]>v[lson]){
                cur=lson;
            }
            if(rson<siz&&v[cur]>v[rson]){
                cur=rson;
            }
            if(cur!=temp){
                swap(v[cur],v[(cur-1)/2]);
                lson=2*cur+1,rson=2*cur+2;
            }
            else break;
        }
    }
    int get_top(){
        return v[0];
    }
    int get_siz(){
        return siz;
    }
    int get_sum(){
        return sum;
    }
};
signed main(){
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    heap h(m);
    int maxn=0;
    for(int i=1;i<=n;i++){
        if(h.get_siz()<m&&a[i]>0){
            h.insert(a[i]);
        }
        else if(a[i]>h.get_top()&&a[i]>0){
            h.pop();
            h.insert(a[i]);
        }
        maxn=max(maxn,h.get_sum()-i*d);
    }
    cout<<maxn<<endl;
    return 0;
}