#include<bits/stdc++.h> 
using namespace std;

int maxprofit(int* num, int n){
    int min= INT_MAX,max= 0;
    for(int i = 0;i<n;i++)
	{
        	if(min>num[i])
		{
            min= num[i];
    	}
			else if(max<num[i]-min)
		{
            max= num[i]-min;
        }
    }
    return max;
}


int main(){
	int n;
	cin>>n;
	int *num=new int[n];
		for(int i=0;i<n;i++)
	{
	 	cin>>num[i];
	}
	cout<<maxprofit(num, n);
	return 0;
}
