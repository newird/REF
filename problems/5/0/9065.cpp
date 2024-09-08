#include <iostream>
using namespace std;

void Movie(int* movies, int last, int now, int trys,int n,int d,int* Max,int happy){
    if(now==n+1 || trys==0){
        *Max = max(*Max,happy);
    }
    else if(movies[now-1]>0){
        Movie(movies,now,now+1,trys-1,n,d,Max,happy+movies[now-1]-d*(now-last));//看
        Movie(movies,last,now+1,trys,n,d,Max,happy);//不看
    }
    else{
        Movie(movies,last,now+1,trys,n,d,Max,happy);//不看
    }
}

int main(){
    int n,m,d;
    cin >> n >> m >> d;
    int* movies = new int[200000];
    for(int i=0;i<n;i++){
        cin >> movies[i];
    }
    int Max;
    Movie(movies,0,1,m,n,d,&Max,0);
    cout << Max;
}