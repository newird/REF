#include<iostream>

using namespace std;

int mpow(int base, int exp);

int main()
{
	int n, m;
	int A[1001];
	int B[1001];
	
	cin >> n >> m;
	
	int sumN = 0;
	int sumM = 0;

	for(int j = 0; j < n; j++){
		cin >> A[j];
	}
	for(int j = 0; j < m; j++){
		cin >> B[j];
	}
	
	for(int i = 0; i < n; i++){
		sumN += A[i] * mpow(10, i);
	//	cout << sumN << endl;
	}
	for(int i = 0; i < m; i++){
		sumM += B[i] * mpow(10, i);
	//	cout << sumM << endl;
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