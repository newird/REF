#include <iostream>

using namespace std;

int path = 0;
int ans = 0;
int sizeOfNums;
int downval;

int fmax(int a, int b){
	return a > b? a : b;
}
void dfs(int index, int chance, int gap, int* nums){
	if(index == sizeOfNums || chance == 0){
		ans = fmax(ans, path);
		return;
	}
	dfs(index + 1, chance, gap + 1, nums);
	path += nums[index] - gap * downval;
	dfs(index + 1, chance - 1, 1, nums);
	path -= nums[index] - gap * downval;
	return;
}

int main(){
	int n, m, d;
	cin >> n >> m >> d;
	sizeOfNums = n;
	downval = d;
	int nums[n];
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	dfs(0, m, 1 , nums);
	cout << ans << endl;
	return 0;
}