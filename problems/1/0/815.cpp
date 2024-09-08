#included<iostream>
using namespace std;
int sum(int n){
int k=0;
for(int i=1;i<=n;i++){
k+=1;}
return k;
}
int main(){
int n;
cin>>n;
if(n>=1){
int s=sum(n);
cout<<s<<endl;}
else{
cout<<-1<<endl;}
return 0;
}