#include<iostream>
using namespace std;
int main(){
	long long a;
	long long b;
	cin>>a>>b;
	int arr1[a];
	int arr2[b];
	int tmp;
	for(int i=0;i<a;i++){
		cin>>tmp;
		arr1[i]=tmp;
	}
		for(int i=0;i<b;i++){
		cin>>tmp;
		arr2[i]=tmp;
	}
	if(a>=b){tmp=a;}
	else{tmp=b;}
	int result[tmp+1];
	int cf=0;
	int p1;
	if(a>b){
		for(int i=0;i<b;i++){
			tmp=arr1[i]+arr2[i];
			if(tmp>=10){
				tmp-=10;
				result[i]=tmp;
				cf=1;
			}
			else{
				result[i]=tmp;
				cf=0;
			}
		}
		for(int i=b;i<a;i++){
			tmp=arr1[i]+cf;
			if(tmp>=10){
				tmp-=10;
				result[i]=tmp;
				cf=1;
			}
			else{
				result[i]=tmp;
				cf=0;
			}
		}
		result[a]=cf;
		if(cf==1){
			cout<<result[a];
		}
		for(int i=a-1;i>-1;i--){
			cout<<result[i];
		}
		cout<<endl;
	}
	if(a==b){
		for(int i=0;i<b;i++){
			tmp=arr1[i]+arr2[i];
			if(tmp>=10){
				tmp-=10;
				result[i]=tmp;
				cf=1;
			}
			else{
				result[i]=tmp;
				cf=0;
			}
		}
		result[a]=cf;
				if(cf==1){
			cout<<result[a];
		}
		for(int i=a-1;i>-1;i--){
			cout<<result[i];
		}
		cout<<endl;
	}
	if(a<b){
		for(int i=0;i<a;i++){
			tmp=arr1[i]+arr2[i];
			if(tmp>=10){
				tmp-=10;
				result[i]=tmp;
				cf=1;
			}
			else{
				result[i]=tmp;
				cf=0;
			}
		}
		for(int i=a;i<b;i++){
			tmp=arr2[i]+cf;
			if(tmp>=10){
				tmp-=10;
				result[i]=tmp;
				cf=1;
			}
			else{
				result[i]=tmp;
				cf=0;
			}		
		}
		result[b]=cf;
				if(cf==1){
			cout<<result[a];
		}
		for(int i=b-1;i>-1;i--){
			cout<<result[i];
		}
		cout<<endl;
	}
	return 0;
}