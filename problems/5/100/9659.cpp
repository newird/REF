#include <iostream>
using namespace std;

void ShiftDown(long long* heap, int start, int m){
    int i = start,j = 2*i+1;
    long long temp = heap[i];
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

int main(){
    int n,m;
    long long d;
    cin >> n >> m >> d;

    long long* movies = new long long[n];
    for(int i=0;i<n;i++){
        cin >> movies[i];
    }
    
    long long ans = 0;
    long long heap[m-1] = {0};
    long long happy=0;
    long long helper=0;
    for(long long j=0;j<n;j++){//使用long long的j以保证d*(j+1)是long long
        if(m<=0){
            break;
        }
        else if(m==1 && movies[j] > 0){
            helper = movies[j]-d*(j+1);
            ans = max(ans,helper);
        }
        else if(movies[j] > 0){//维护m-1的最小堆，以获得前m-1大的数    
            helper = happy + movies[j] - d*(j+1);
            ans = max(ans, helper);
            if(movies[j] > heap[0]){
                happy += (movies[j] - heap[0]);
                heap[0] = movies[j];
                ShiftDown(heap,0,m-1);
            }
        }
        else{//烂片不看
            continue;
        }
    }

    cout << ans <<endl;
    
    return 0;

}