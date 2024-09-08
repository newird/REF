#include <iostream>

using namespace std;
class MinHeap{
public:
	MinHeap(int sz){
		maxHeapSize = sz;
		heap = new int[maxHeapSize];
		currentSize = 0;
	};
	MinHeap(int arr[], int n);
	~MinHeap(){
	delete []heap;
	}
	int top();
	bool Insert(const int& x);
	bool RemoveMin();
	bool IsEmpty()const {
		return (currentSize == 0)? true : false;
	}
	bool IsFull()const {
		return (currentSize == maxHeapSize)? true : false;
	}
	void MakeEmpty(){
		currentSize = 0;
	}
	int size()const{
		return currentSize;
	}
private:
	int* heap;
	int currentSize;
	int maxHeapSize;
	void siftDown(int start, int m);
	void siftUp(int start);
};

void MinHeap::siftDown(int start, int m){
	int i = start, j = 2 * i + 1;
	int temp = heap[i];
	while(j <= m){
		if(j < m && heap[j] > heap[j+1]){
			j++;
		}
		if(temp <= heap[j]){
			break;
		}else{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;
};

void MinHeap::siftUp(int start){
	int j = start, i = (j - 1)/2;
	int temp = heap[j];
	while(j > 0){
		if(heap[i] <= temp){
			break;
		}else{
			heap[j] = heap[i];
			j = i;
			i = (i-1)/2;
		}
	}
	heap[j] = temp;
};

bool MinHeap::Insert(const int& x){
	if(currentSize == maxHeapSize){
		return false;
	}
	heap[currentSize] = x;
	siftUp(currentSize);
	currentSize++;
	return true;
};

bool MinHeap::RemoveMin(){
	if(0 == currentSize){
		return false;
	}
	heap[0] = heap[currentSize - 1];
	currentSize--;
	siftDown(0, currentSize - 1);
	return true;
}


int MinHeap::top() {
	return currentSize > 0? heap[0] : 114514;
}

//end for the definition for MinHeap
int fmax(int a,int  b){
	return a > b? a : b;
}
int main(){
	int n, m, d;
	cin >> n >> m >> d;
	int nums[n];
	int ans = 0;
	int res = 0;
	MinHeap h(n + 1);
	for(int i = 0; i < n; i++){
		if(h.size() < m){
			int change = nums[i] - d;
			res += change;
			ans = fmax(res, ans);
			h.Insert(nums[i]);
		}else{
			if(nums[i] > h.top()){
				int change = nums[i] - h.top() - d;
				res += change;
				ans = fmax(res, ans);
				h.RemoveMin();
				h.Insert(nums[i]);
			}else{
				res -= d;
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}