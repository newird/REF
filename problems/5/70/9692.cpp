#include<iostream>
#include<cmath>
#include<assert.h>
#include<stdlib.h>
#include <stdio.h>
using namespace std;

const int Defaultsize = 50;

template<class T>
class Pqueue {
protected:
	T* pqelements;
	int count;
	int maxSize;
public:
	Pqueue(int sz= Defaultsize) :maxSize(sz), count(0) {
		pqelements = new T[maxSize];
		assert(pqelements != NULL);
	};

	void adjust() {
		T temp = pqelements[count - 1];
		int j;
		for (j = count - 2; j >= 0; j--)
			if (pqelements[j] <= temp)
				break;
			else pqelements[j + 1] = pqelements[j];
		pqelements[j + 1] = temp;
	}
	bool insert(T& x) {
		if (count == maxSize)
			return false;
		pqelements[count++] = x;
		adjust();
	}
	bool IsEmpty() {
		return (count == 0) ? true : false;
	}
	bool removeMin(T& x) {
		if (count == 0)
			return false;
		x = pqelements[0];
		for (int i = 0; i < count; i++)
			pqelements[i - 1] = pqelements[i];
		count--;
		return true;
	}
	bool getfront(T& x) {
		if (count == 0)
			return false;
		else
		{
			x = pqelements[0];
			return true;
		}
	}
	int getsize() {
		return count;
	}
};

template<class E>
class minheap {
private:
	E* heap;
	int currentsize;
	int maxsize;
	//下滑调整
	void siftdown(int start, int m) {
		int i = start, j = 2 * i + 1;
		E temp = heap[i];
		while (j <= m) {
			if (j<m && heap[j]>heap[j + 1])
				j++;
			if (temp <= heap[j])
				break;
			else
			{
				heap[i] = heap[j];
				i = j;
				j = 2 * j+ 1;
			}
		}
		heap[i] = temp;
	};
	void siftup(int start) {
		int j = start;
		int i = (j - 1) / 2;
		E temp = heap[j];
		while (j > 0)
		{
			if (heap[i] <= temp)break;
			else
			{
				heap[j] = heap[i];
				j = i;
				i = (i - 1) / 2;
			}
		}
		heap[j] = temp;
	};

public:
	minheap(int sz) {
		maxsize = sz;
		heap = new E[maxsize];
		if (heap == NULL)
		{
			cerr << "存储分配失败" << endl;
		}
		currentsize = 0;
	}
	minheap(E arr[], int n) {
		maxsize = n;
		heap = new E[maxsize];
		if (heap == NULL)
		{
			cerr << "存储分配失败" << endl;
		}
		for (int i = 0; i < n; i++)
			heap[i] = arr[i];
		currentsize = n;
		int currentP = (currentsize - 2) / 2;
		while (currentP >= 0) {
			siftdown(currentP, currentsize - 1);
			currentP--;
		}
	}
	bool INsert(E& x) {
		if (currentsize == maxsize)
		{
			cerr << "heap full" << endl;
			return false;
		}
		heap[currentsize] = x;
		siftup(currentsize);
		currentsize++;
		return true;
	}
	bool removeMIN(E&x) {
		if (!currentsize)
		{
			cout << "heap empty" << endl;
			return false;
		}
		x = heap[0];
		heap[0] = heap[currentsize - 1];
		currentsize--;
		siftdown(0, currentsize - 1);
		return true;
	}
	int getSIZE() {
		return currentsize;
	}
	bool getFRONT(E& x) {
		if (!currentsize)
			return false;
		x= heap[0];
		return true;
	}
	void print() {
		for (int i = 0; i < currentsize; i++)
			cout << heap[i] << " ";
		cout << endl;
	}
};
//inline void readint(int& a) {
//	a = 0; char c; int sgn = 1;
//	while ((c = getchar()) < 48) if (c == '-') sgn = -1;
//	do a = a * 10 + (c ^ 48);
//	while ((c = getchar()) > 47);
//	a *= sgn;
//}

int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	int* hap = new int[n+1];
	for (int i = 1; i <= n; i++)
		cin >> hap[i];
	int max_hap = 0, index = 0;
	int fw = 0, last_day = 0;
	minheap<int> cinema(n);
	for (int i = 1; i <= n; i++)
	{
		
		if (cinema.getSIZE() < m)
		{
			if (hap[i] > 0)
			{
				index += hap[i];
				index -= d * (i - last_day);
				//如果这是最后一天看电影
				max_hap = std::max(max_hap, index);
				cinema.INsert(hap[i]);
				last_day = i;
			}
		}
		else
		{
			int x;
			cinema.getFRONT(x);
			if (hap[i] >= x)
			{
				/*if (hap[i] > (x + d * (i - last_day)))
				{
					index += hap[i];
					index -= d * (i - last_day);
					index -= x;
					max_hap = std::max(max_hap, index);
				}*/
				index += hap[i];
				index -= d * (i - last_day);
				index -= x;
				max_hap = std::max(max_hap, index);
				cinema.removeMIN(x);
				cinema.INsert(hap[i]);
				last_day = i;
			}
		}
	}
	cout << max_hap;
}