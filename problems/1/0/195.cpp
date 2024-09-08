#include<iostream>
using namespace std;
int N;
int main()
{
cin>>N;
long long int answer=0;
if(N<1)
return -1;
else
{
for(int i=1;i<=N;i++)
answer+=i;
cout<<answer<<endl;
}
}