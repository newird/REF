#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, d;
	cin >> n >> m >> d;

	vector<int> happiness(n);
	for (int i = 0; i < n; i++) {
		cin >> happiness[i];
	}

	sort(happiness.begin(), happiness.end());

	int max_happiness = 0;
	int idx = 0;

	while (m> 0 && idx < n) {
		max_happiness += happiness[idx];
		idx +=d ;
		m--;
	}

	cout << max_happiness << endl;

	return 0;
}