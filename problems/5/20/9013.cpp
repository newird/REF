#include <iostream>
using namespace std;

int Movie(int* movies, int last, int now, int trys,int n,int d){
    if(now==n){
        return 0;
    }
    if(trys==0){
        return 0;
    }
    int see = Movie(movies,now,now+1,trys-1,n,d)+movies[now]-d*(now-last);
    int learn = Movie(movies,last,now+1,trys,n,d);
    return max(see,learn);
}

int main(){
    int n,m,d;
    cin >> n >> m >> d;
    int* movies = new int[200000];
    for(int i=0;i<n;i++){
        cin >> movies[i];
    }
    cout << Movie(movies,0,1,m,n,d);
}