#include <iostream>
using namespace std;

void heapifyUp(int arr[], int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (arr[i] < arr[parent]) {
            swap(arr[i], arr[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

void buildHeap(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        heapifyUp(arr, i);
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
                buildHeap(heap,sees);
            }
            else{
                ans = max(ans, happy + movies[j] - d*(j+1));
                if(movies[j] > heap[0]){
                    happy += (movies[j] - heap[0]);
                    heap[0] = movies[j];
                    buildHeap(heap,m-1);
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