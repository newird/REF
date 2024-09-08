#include<bits/stdc++.h>
using namespace std;
int Heap[400005],t;
void hpush(int x)
{
    Heap[++t]=x;
    int curr=t;
    while (curr>1)
    {
        if (Heap[curr>>1]>Heap[curr])
        {
            int sw=Heap[curr>>1];
            Heap[curr>>1]=Heap[curr];
            Heap[curr]=sw;
            curr>>=1;
        }
        else break;
    }
}
void hpop()
{
    int curr=1;
    Heap[curr]=Heap[t--];
    while (curr<<1<=t)
    {
        int min=curr<<1;
        if (curr<<1|1<=t && Heap[min]>Heap[curr<<1|1]) min=curr<<1|1;
        if (Heap[min]<Heap[curr])
        {
            int sw=Heap[min];
            Heap[min]=Heap[curr];
            Heap[curr]=sw;
            curr=min;
        }
        else break;
    }
}
int main()
{   
    int n,m,d,x;
    long long tot=0,ans=0;
    scanf("%d %d %d",&n,&m,&d);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if (x>0) {hpush(x); tot+=x;}
        if (t>m) 
        {
            tot-=Heap[1];
            hpop();
        }
        ans=max(ans,tot-(long long)i*d);
    }
    printf("%lld\n",ans);
    return 0;
}