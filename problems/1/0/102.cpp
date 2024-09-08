#include <stdio.h>

int main(){
   int n,ans=0;
   scanf("%d",&n);
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
