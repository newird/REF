#include<stdio.h>
int main(){
    int n,m;
    scanf("%d %d", &n,&m);
    int Num1[500001] = {0,};
    int Num2[500001] = {0,};
    for(int i = 0; i < n; i++){
        scanf("%d", &Num1[i]);
    }
    int ans[500002] = {0,};
    for(int i = 0; i < m; i++){
        scanf("%d", &Num2[i]);
    }
    int CF = 0;
    int fetch1, fetch2, res;
    int lenth = 0;
    if(m <= n){
        for(int i = 0; i < m; i++){
            fetch1 = Num1[i];
            fetch2 = Num2[i];
            if(fetch1 + fetch2 + CF >= 10){
                res = fetch1 + fetch2 + CF - 10;
                ans[lenth++] = res;
                CF = 1;
            }else{
                res = fetch1 + fetch2 + CF;
                ans[lenth++] = res;
                CF = 0;
            }
        }
        for(int i = m; i < n; i++){
            fetch1 = Num1[i];
            if(fetch1+ CF >= 10){
                res = fetch1 + CF - 10;
                ans[lenth++] = res;
                CF = 1;
            }else{
                res = fetch1 + CF;
                ans[lenth++] = res;
                CF = 0;
            }
        }
        if(CF == 1){
            ans[lenth++] = 1;
        }
    }else{
        for(int i = 0; i < n; i++){
            fetch1 = Num1[i];
            fetch2 = Num2[i];
            if(fetch1 + fetch2 + CF >= 10){
                res = fetch1 + fetch2 + CF - 10;
                ans[lenth++] = res;
                CF = 1;
            }else{
                res = fetch1 + fetch2 + CF;
                ans[lenth++] = res;
                CF = 0;
            }
        }
        for(int i = n; i < m; i++){
            fetch1 = Num2[i];
            if(fetch1+ CF >= 10){
                res = fetch1 + CF - 10;
                ans[lenth++] = res;
                CF = 1;
            }else{
                res = fetch1 + CF;
                ans[lenth++] = res;
                CF = 0;
            }
        }
        if(CF == 1){
            ans[lenth++] = 1;
        }
    }
    for(int i = lenth - 1; i >= 0; i--){
        printf("%d", ans[i]);
    }
    return 0;
}