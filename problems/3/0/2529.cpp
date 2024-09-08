#include<iostream>
using namespace std;

int main()
{
   int n,m;
   cin>>n>>m;
   int arr1[n];
   int arr2[m];
   int k=(n>=m? n:m);
   int arr3[k];
   int cin=0;
   for(int i=0;i<n;i++){
      cin>>*(arr1+i);
   }
   for(int i=0;i<m;i++){
      cin>>*(arr2+i);
   }
   for(int i=0;i<k;i++){
      if(i<m&&i<n)arr3[i]=arr1[i]+arr2[i]+cin;
      else if(i<m) arr3[i]=arr2[i]+cin;
      else arr3[i]=arr1[i]+cin;
      if(arr3[i]>9){arr3[i]-=10;cin=1;}
      else cin=0;
  }
   if(cin==1)cout<<1;
   for(int i=0;i<k;i++){
       cout<<arr3[i];
   }
}