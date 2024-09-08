#include <iostream>
using namespace std;

void ShiftDown(int* heap, int start, int m){
    int i = start,j = 2*i+1;
    int temp = heap[i];
    while(j<=m){
        if(j<m && heap[j] > heap[j+1])j++;
        if(temp <= heap[j])break;
        else{
            heap[i] = heap[j];
            i = j;
            j = 2*j+1;
        }
    }
    heap[i] = temp;
}

void ShiftUp(int* heap, int start){
    int j = start, i = (j-1)/2;
    int temp = heap[j];
    while(j>0){
        if(heap[i] <= temp)break;
        else{
            heap[j] = heap[i];
            j = i;
            i = (i-1)/2;
        }
    }
    heap[j] = temp;
}

void insert(int* heap, int type, int val, int size){//未满直接入:type=0 已满取代尖:type=1
    if(type){
        heap[0] = val;
        ShiftDown(heap,0,size);
    }
    else{
        heap[size] = val;
        ShiftUp(heap,size);
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
    heap[0] = 0;
    int sees = 0;//记录堆中元素个数：看过的电影数
    long long happy=0;
    for(long long j=0;j<n;j++){//使用long long的j以保证d*(j+1)是long long
        if(m<=0){
            break;
        }
        else if(m==1 && movies[j] > 0){
            ans = max(ans,movies[j]-d*(j+1));
        }
        else if(movies[j] > 0){//维护m-1的最小堆，以获得前m-1大的数
            if(sees < m-1){
                heap[sees] = movies[j];
                happy += movies[j];
                ans = max(ans, happy-d*(j+1));
                sees++;
                insert(heap,0,movies[j],sees);
            }
            else{
                ans = max(ans, happy + movies[j] - d*(j+1));
                if(movies[j] > heap[0]){
                    happy += (movies[j] - heap[0]);
                    insert(heap,1,movies[j],m-1);
                    sees++;
                }
            }
        }
        else{//烂片不看
            continue;
        }
    }

    cout << ans <<endl;
    
    return 0;

}