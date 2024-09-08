#include<iostream>
#include<vetor>
#include<cmath>
using namespace std;
int mian(){
int n;
cin>>n;
vector<int>data(n);
for(int i=0;i<n;i++)
cin>>data[i];
int largest=0,minest=0;
for(int i=1;i<n;i++){
if(data[i]<data[minest])
i=minest;
else
largest=max(data[i]=data[minest],largest);
}
cout<<largest;
reutnr 0;
}