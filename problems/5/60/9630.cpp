#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void adjust(long long* minheap,int p,int size){//p为指定的"堆顶" 不一定是minheap[0] 因而允许局部调整
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
    
    //priority_queue<long long, vector<long long>, greater<long long>> heap;

    int* movies = new int[n];
    for(int i=0;i<n;i++){
        cin >> movies[i];
    }

    long long* ans = new long long[n];
    long long* heap = new long long[m];
    int sees = 0;//记录堆中元素个数：看过的电影数
    long long happy=0;
    for(int j=0;j<n;j++){
        if(movies[j] <= 0){//烂片不看
            continue;
        }
        else{
            if(sees < m){//机会还没用完 随便看
                heap[sees] = movies[j];
                //heap.push(movies[j]);
                happy += movies[j];
                ans[sees] = happy-d*(j+1);
                sees++;
                adjust(heap,0,sees);
            }
            else{   
                if(movies[j] >= heap[0]){
                //if(movies[j] >= heap.top()){
                    happy += movies[j] - heap[0];
                    //happy += movies[j] - heap.top();
                    heap[0] = movies[j];
                    //heap.pop();
                    //heap.push(movies[j]);
                    adjust(heap,0,m);
                    ans[sees] = happy-d*(j+1);
                    sees++;
                }
                else{
                    continue;
                }
            }
        }
    }

    long long max_happy = 0;

    for(int k=0;k<sees;k++){
        max_happy = max(max_happy,ans[k]);
    }

    cout << max_happy <<endl;
    
    return 0;

}