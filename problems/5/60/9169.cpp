#include <iostream>
using namespace std;

int main(){
    int n,m,d;
    cin >> n >> m >> d;

    int deserve = 0;//累计的负值
    int last = 0;//上一次观看电影的日子
    int happy = 0;//幸福值
    int movie = 0;//扫描用容器

    for(int i=0;i<n;i++){
        cin >> movie;
        if(m<=0){
            break;;
        }
        if(movie>0){
            deserve = deserve + movie - d*(i-last+1) < 0 ? deserve + movie - d*(i-last+1) : 0 ;
            happy += movie - d*(i-last+1);
            last = i+1;
            m--;
        }
        
    }

    if(deserve<0){
        happy -= deserve;
    }

    cout << happy;
    
}