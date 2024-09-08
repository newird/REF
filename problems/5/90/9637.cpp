#include <iostream>
using namespace std;

void adjust(int* minheap,int p,int size){//p为指定的"堆顶" 不一定是minheap[0] 因而允许局部调整
    while(2*p+1<size){
        int left = 2*p+1;
        int right = 2*p+2;
        int change = (right < size && minheap[right] < minheap[left]) ? right:left;
        if(minheap[change] < minheap[p]){
            swap(minheap[change],minheap[p]);
        }
        else{
            break;
        }
        p = change;
    }
}

int main(){
    int n,m,d;
    cin >> n >> m >> d;

    int* movies = new int[n];
    for(int i=0;i<n;i++){
        cin >> movies[i];
    }
    
    long long ans = 0;
    int* heap = new int[m];
    int sees = 0;//记录堆中元素个数：看过的电影数
    long long happy=0;
    for(long long j=0;j<n;j++){
        if(movies[j] <= 0){//烂片不看
            continue;
        }
        else{
            if(sees < m-1){//机会还没用完 随便看
                heap[sees] = movies[j];
                happy += movies[j];
                ans = max(happy - (long long)d * (long long)(j + 1), ans);
                sees++;
                adjust(heap,0,sees);
            }
            else{
                ans = max(happy + movies[j] - (long long)d * (long long)(j + 1), ans);
                if(movies[j] >= heap[0]){
                    happy += movies[j] - heap[0];
                    heap[0] = movies[j];
                    adjust(heap,0,m-1);
                }
                else{
                    continue;
                }
            }
        }
    }

    cout << ans <<endl;
    
    return 0;

}