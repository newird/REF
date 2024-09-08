#include <iostream>
using namespace std;
class Minheap
{
    long long*heap;
    long long currentsize;
    long long Minsize;
public:
    Minheap(long long sz) {
        Minsize=sz;
        heap=new long long[sz];
        currentsize=0;
    }

    void siftdown(long long start,long long m){
        long long i=start;
        long long j=2*i+1;
        long long temp=heap[i];
        while(j<=m){
            if(j<=m&&heap[j]>heap[j+1])
                j++;
            if(temp<=heap[j])
                break;
            else {
                heap[i]=heap[j];i=j;
                j=2*i+1;
            }
        }
        heap[i]=temp;
    }
    void siftup(long long start){
        long long j=start,i=(j-1)/2;
        long long temp=heap[j];
        while(j>0){
            if(heap[i]<=temp)break;
            else{
                heap[j]=heap[i];
                j=i;
                i=(i-1)/2;
            }
        }
        heap[j]=temp;
    }

    void insert(long long c){
        heap[currentsize]=c;
        siftup(currentsize);
        currentsize++;
    }
    void erase(){
        heap[0]=heap[currentsize-1];
        currentsize--;
        siftdown(0,this->currentsize-1);
    }
    long long gettop(){
        return heap[0];
    }
    void checkdata(){
        for(long long i=0;i<currentsize;i++)
            cout<<heap[i]<<" ";
        cout<<endl;
    }
};
int main()
{
    long long n,m,d;
    cin>>n>>m>>d;
    long long*data=new long long[n];
    for(long long i=0;i<n;i++)
        cin>>data[i];
    if(m==0){
        cout<<"0";
        return 0;
    }
    Minheap h(m);
    long long res=0;
    long long sum=0;
    long long las=0;
    long long sz=0;
    while(las<n){
        long long temp=(long long)data[las]-d*(las+1);
        if(m>1&&las>=1){
            if(data[las-1]>0){
                h.insert(data[las-1]);
                sz++;
                sum+=data[las-1];
                if(sz==m){
                    sum-=h.gettop();
                    h.erase();
                    sz--;
                }
            }
        }
        if(sum+temp>res)
            res=sum+temp;
        las++;
    }
    cout<<res;
    return 0;
}