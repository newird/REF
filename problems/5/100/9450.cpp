using namespace std;
#include <iostream>

//void search(int a[], int pos[], int id, int len, int left, int d, long long sum, long long& max) {
//	if (left == 0 || id == len) return;
//	else {
//		search(a, pos, id + 1, len, left, d, sum, max);
//		//if ([a[id] > 0) 
//		sum += (long long)a[id];
//		long long temp = sum - (long long)d * (pos[id] + 1);
//		if (temp > max) max = temp;
//		search(a, pos, id + 1, len, left - 1, d, sum, max);
//	}
//	return;
//}

struct minheap {
public:
	int max;
	int size;
	long long sum;
	int* tree;
	minheap(int s) {
		max = s;
		tree = new int[s];
		size = 0;
		sum = 0;
	}
	void insert(int i) {
		int p;
		int lchild;
		int rchild;
		int min;
		if (size < max) {
			p = size;
			size++;
			sum += (long long)i;
			//filter up
			int father = (p - 1) / 2;
			while (true) {
				if (tree[father] > i) {
					tree[p] = tree[father];
					p = father;
					father = (p - 1) / 2;
					if(p == 0) break;
				}
				else break;
			}
			tree[p] = i;
		}
		else {
			if (size > 0 && i > tree[0]) {
				sum -= tree[0];
				sum += (long long)i;
				//filter down
				p = 0;
				lchild = 2 * p + 1;
				rchild = 2 * p + 2;
				while (lchild<size) {
					if (rchild >= size) {
						if (tree[lchild] < i) {
							tree[p] = tree[lchild];
							p = lchild;
							break;
						}
						else break;
					}
					min = tree[lchild] > tree[rchild] ? tree[rchild] : tree[lchild];
					if (i <= min) {
						break;
					}
					else {
						if (tree[lchild] > tree[rchild]) {
							tree[p] = tree[rchild];
							p = rchild;
							lchild = 2 * p + 1;
							rchild = 2 * p + 2;
						}
						else { 
							tree[p] = tree[lchild]; 
							p = lchild;
							lchild = 2 * p + 1;
							rchild = 2 * p + 2;
						}
					}
				}
				tree[p] = i;
			}
		}
	}
	//void print() {
	//	for (int i = 0; i < size; i++) {
	//		cout << tree[i];
	//		cout << " ";
	//	}
	//	cout << endl;
	//};

};

int main() {
	long long max = 0;
	int n, m, d;
	cin >> n >> m >> d;
	int* a = new int[n];
	int* pos = new int[n];
	int in;	
	int top = 0;
	//S1 we only need to consider positive nums
	//as negtive nums must be useless O(n)
	for (int i = 0; i < n; i++) {
		cin >> in;
		if (in > 0) {
			a[top] = in;
			pos[top] = i;
			top++;
		}
	}
	//S2 here we traverse from the first positive num to the last 
	// as the end of the chosen days O(n)
	//S3 for each end day, the cost pay*gap is determined
	//so all the previous positive days would help increase the answer
	//S4 as the max num of days chosen is limited
	// for a certain end day, we must figure out the 1st - (m-1)th largest days
	// so use a min heap to keep the 1st - (m-1)th largest days	O(logn)
	//total O(nlogn)
	minheap* h = new minheap(m-1);
	long long tempsum;
	for (int i = 0; i < top; i++) {
		tempsum = h->sum + (long long)a[i] - ((long long)d)*((long long)(pos[i] + 1));
		//cout << tempsum;
		//cout << " ";
		//cout<< h->sum << endl;
		if (tempsum > max) max = tempsum;
		h->insert(a[i]);
		//h->print();
	}
	//search(a, pos, 0, top, m, d, 0, max);
	cout << max << endl;
	return 0;
}