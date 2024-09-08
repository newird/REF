#include<iostream>
using namespace std;
int main(){
	int temp;
	int day;
	cin>>day;
	int max;
	int min;
	int result;
	int z=1;
	for(int i=0;i<day;i++){
		cin>>temp;
		if(i==0){
			max=temp;
			min=temp;
		}
		if(temp>max){
			max=temp;
		}
		if(min>temp){
			min=temp;
			z+=1;
		}
	}
	result=max-min;
	if(z==day){result=0;}
	cout<<result;
	return 0;
}