#include<iostream>
using namespace std;
int main(){
	int temp;
	int day;
	cin>>day;
	int a[day];
	int min;
	int max=0;
	int st;
	int result=0;
	int z=1;
	for(int i=0;i<day;i++){
		cin>>temp;
		a[i]=temp;
		if(i==0){min=temp;}
		if(min>temp){
			min=temp;
			z+=1;
		}
	}
	for(int i=0;i<day;i++){
		if(max>result){result=max;}
		for(int j=i;j<day;j++){
			st=a[i];
			if(j==i){min=a[j];}
			if(min>a[j]){
				min=a[j];
				max=a[i]-a[j];
			}
		}
	}
	if(z==day){result=0;}
	cout<<result;
	return 0;
}