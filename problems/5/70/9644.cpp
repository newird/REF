#include <iostream>
using namespace std;

void heapify(int arr[], int size, int i) {
    int smallest = i; // 初始化父节点为最小值
    int left = 2 * i + 1; // 左子节点的索引
    int right = 2 * i + 2; // 右子节点的索引

    // 如果左子节点比父节点小，更新最小值的索引
    if (left < size && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // 如果右子节点比父节点小，更新最小值的索引
    if (right < size && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // 如果最小值的索引不是父节点的索引，交换它们
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // 递归地继续向下调整子树
        heapify(arr, size, smallest);
    }
}

void adjust(int arr[], int size) {
    // 从最后一个非叶子节点开始向上调整
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
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
                adjust(heap,sees);
            }
            else{
                ans = max(ans, happy + movies[j] - d*(j+1));
                if(movies[j] > heap[0]){
                    happy += (movies[j] - heap[0]);
                    heap[0] = movies[j];
                    adjust(heap,m-1);
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