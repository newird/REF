#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,m,i,s,CF;
    scanf("%d",&n);
    scanf("%d",&m);
    char* a = (char*)malloc(n*sizeof(char));
    char* b = (char*)malloc(m*sizeof(char));
    char* res = (char*)malloc(((m>n)?(m):(n)+1)*sizeof(char));
    for(i=0;i<n;i++){
        scanf("%s",&s);
        a[i] = (char)(s);
    }
    for(i=0;i<m;i++){
        scanf("%s",&s);
        b[i] = (char)(s);
    }
    if(m>n){
        //b>a
        CF = 0;
        for(int i=0;i<n;i++){
            s = ((a[i] - '0')+b[i] - '0'+CF)%10;
            CF = ((a[i] - '0')+b[i] - '0'+CF)>9;
            res[i] = (char)(s);
        }
        for(int i=n;i<m;i++){
            s = (b[i] - '0'+CF)%10;
            CF = (b[i] - '0'+CF)>9;
            res[i] = (char)(s);
        }
    }
    else{
        //a>=b
        CF = 0;
        for(int i=0;i<m;i++){
            s = ((a[i] - '0')+(b[i] - '0')+CF)%10;
            CF = ((a[i] - '0')+(b[i] - '0')+CF)>9;
            res[i] = (char)(s);
        }
        for(int i=m;i<n;i++){
            s = ((a[i] - '0')+CF)%10;
            CF = ((a[i] - '0')+CF)>9;
            res[i] = (char)(s);
        }
    }
    if(CF){printf("1");}
    for(int i=((m>n)?(m):(n))-1;i>=0;i--){
        printf("%d",res[i]);
    }
    return 0;
}