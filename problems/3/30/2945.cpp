#include<iostream>

using namespace std;

int mpow(int base, int exp);

int main()
{
	int n, m;
///	long long A[1001];
	//long long B[1001];
	
	cin >> n >> m;
	
	long long sumN = 0;
	long long sumM = 0;
	
	int a = 0;
	int b = 0;

	for(int j = 0; j < n; j++){
		cin >> a;
		sumN += a * mpow(10, j);
		//cout << sumN << endl;
	}
	for(int j = 0; j < m; j++){
		cin >> b;
		sumM += b * mpow(10, j);
		//cout << sumM << endl;
	}
	
	cout << sumN + sumM; 
	
}

int mpow(int base, int exp){
	int res = 1;
	while(exp){
		if(exp & 1){
			res *= base;
		}
		exp >>= 1;
		base *= base;
	}
	return res;
}