#include <iostream>

using namespace std;


void quicksort(pair<int,int>* arr,int left,int right){
		int i,j;
		pair<int,int> k, temp;
		if(left > right) return;
		temp = arr[left];
		i=left; j=right;
		while(i!=j){
			while(arr[j].first <= temp.first && i < j)
			    j--;
			while(arr[i].first >= temp.first && i < j)
			    i++;
			if(i < j){
				k=arr[i];
				arr[i]=arr[j];
				arr[j]=k;
			}
		}	
		arr[left]=arr[i];
		arr[i]=temp;
		quicksort(arr, left,i-1);
		quicksort(arr, i+1,right);
		return;
}

int fmax(int a, int b){
	return a > b? a : b;
}
int main(){
	int n, m, d;
	cin >> n >> m >> d;
	int nums[n];
	pair<int,int> PairSet[n];
	for(int i = 0; i < n; i++){
		cin >> nums[i];
		pair<int,int> p(nums[i], i);
		PairSet[i] = p;
	}
	quicksort(PairSet, 0, n-1);
	int ans = 0;
	int res = 0;
	for(int i = 0; i < n; i++){
		if(nums[i] < 0){
			continue;
		}
		ans = 0;
		int chance = m - 1;
		ans -= d * i;
		ans += nums[i];
		int start = 0;
		while(start < n && chance > 0 && PairSet[start].first > 0){
			if(PairSet[start].second < i){
				ans += PairSet[start].first;
				chance--;	
			}
			start++;
		}
		res = fmax(res, ans);
	}
	cout << res << endl;
	return 0;
}