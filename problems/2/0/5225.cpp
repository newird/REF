#include<iostream>
using namespace std;
int main(){
	int temp;
	int day;
	cin>>day;
	int a[day];
	int end;
	int max=0;
	int st;
	int result=0;
	for(int i=0;i<day;i++){
		cin>>temp;
		a[i]=temp;
		}
	}
	for(int i=0;i<day;i++){
		if(max>result){result=max;}
		for(int j=i;j<day;j++){
			st=a[i];
			if(j==i){end=a[j];}
			if(end<a[j]){
				end=a[j];
				max=a[j]-a[i];
			}
		}
	}
	cout<<result;
	return 0;
}