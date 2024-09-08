#include <stdio.h>

int main(){
   long long n,ans=0;
   scanf("%ld",&n);
   if(n<1){
      ans=-1;
   }
   else{
      for(n;n>=1;n--){
         ans+=n;
      }
   }
   printf("%d",ans);
}
