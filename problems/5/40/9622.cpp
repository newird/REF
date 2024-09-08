#include <iostream>
using namespace std;

int sum(int* array,int len){
    int ans=0;
    for(int i=0;i<len;i++){
        ans+=array[i];
    }
    return ans;
}

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

    int* ans = new int[n];
    int* heap = new int[m];
    int sees = 0;//记录堆中元素个数：看过的电影数
    
    for(int j=0;j<n;j++){
        if(movies[j] <= 0){//烂片不看
            continue;
        }
        else{
            if(sees < m){//机会还没用完 随便看
                heap[sees] = movies[j];
                ans[sees] = sum(heap, sees+1)-d*(j+1);
                sees++;
                if(sees == m){//当前使用的是最后一次机会 堆满 进行调整
                    adjust(heap,0,m);
                }
            }
            else{   
                if(movies[j] >= heap[0]){
                    heap[0] = movies[j];
                    adjust(heap,0,m);
                    ans[sees] = sum(heap, m)-d*(j+1);
                    sees++;
                }
                else{
                    continue;
                }
            }
        }
    }

    int max_happy = INT32_MIN;

    for(int k=0;k<sees;k++){
        max_happy = max(max_happy,ans[k]);
    }

    cout << max_happy <<endl;
    
    return 0;

}