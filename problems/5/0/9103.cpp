//
//  main.cpp
//  good film
//
//  Created by 许煜恒 on 11/2/23.
//

#include <iostream>
using namespace std;

#define MAXM 2*100000

class MinHeap{
public:
    int numbers[MAXM];
    int w=0;
    long long sum=0;
    int sizecap;
    
    MinHeap(int sizecap){
        this->sizecap=sizecap;
    }
    
    void insert(int data){
        if(w==sizecap) pop();
        
        numbers[w++]=data;
        sum+=data;
        
        int p=w-1;
        while(p>=0){
            int pp=parent(p);
            if(numbers[p]<numbers[pp]){
                swap(&numbers[p], &numbers[pp]);
                p=pp;
            }else{
                break;
            }
        }
        
    }
    
    /*
     * Pop min data
     */
    int pop(){
        if(w<=0){
            printf("Poping an empty heap!!\n");
            exit(100);
        }
        
        int result=numbers[0];
        swap(&numbers[0],&numbers[w-1]);
        w--;
        
        int p=0;
        while(p<w){
            int min=p,l=left(p),r=right(p);
            if(l<w && numbers[l]<numbers[min]) min=l;
            if(r<w && numbers[r]<numbers[min]) min=r;
            if(p!=min){
                swap(&numbers[p],&numbers[min]);
                p=min;
            }else{
                break;
            }
        }
        sum-=result;
        
        return result;
    }
    
    int min(){
        if(w<=0){
            printf("Getting value from an empty heap!!\n");
            exit(100);
        }
        
        return numbers[0];
    }
    
private:
    int parent(int idx){
        return (idx-1)/2;
    }
    
    int left(int idx){
        return 2*idx+1;
    }
    
    int right(int idx){
        return 2*idx+2;
    }
    
    void swap(int *a, int *b){
        int tmp=*a;
        *a=*b;
        *b=tmp;
    }
    
};

void testMinHeap(){
    MinHeap a(10);
    
    a.insert(0);
    for(int i=1;i<100;i++){
        if(a.min()<i) a.insert(i);
    }
    
    for(int i=0;i<a.w;i++) printf("%d ",a.numbers[i]);
    printf("sum=%lld\n",a.sum);
    
}

int main(int argc, const char * argv[]) {
    int n,m,d;
    cin>>n>>m>>d;
    
    MinHeap maxones(m);
    long long maxHappiness[n];
    
    int current;
    for(int i=0;i<n;i++){
        cin>>current;
        if(current<0){
            maxHappiness[i]=i>0?(maxHappiness[i-1]):0;
            continue;
        }
        
        if(maxones.w<maxones.sizecap || current>maxones.min()) maxones.insert(current);
        maxHappiness[i]=maxones.sum-(i+1)*d;
    }
    
    long long maxh=0;
    for(int i=0;i<n;i++)
        if(maxHappiness[i]>maxh)
            maxh=maxHappiness[i];
    
    cout<<maxh<<endl;
    
//    for(int i=0;i<maxones.w;i++) printf("%d ",maxones.numbers[i]);
//    printf("sum=%d\n",maxones.sum);
    
    
    return 0;
}
