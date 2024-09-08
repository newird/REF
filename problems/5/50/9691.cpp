#include <iostream>
#include<string>
#include<vector>
#include <stdio.h>
#include<queue>
#include<cmath>
using namespace std;

inline void readint(int& a) {
    a = 0; char c; int sgn = 1;
    while ((c = getchar()) < 48) if (c == '-') sgn = -1;
    do a = a * 10 + (c ^ 48);
    while ((c = getchar()) > 47);
    a *= sgn;
}

    void minHeapify(int* a, int s,int m) 
    {
        int i = s; int j = 2 * i + 1;
        int t = a[i];
        while (j <= m)
        {
            if (j<m && a[j]>a[j + 1])j++;
            if (t <= a[j])break;
            else
            {
                a[i] = a[j]; i = j; j = 2 * j + 1;
            }
        }
        a[i] = t;
    }

    void build(int* a, int heapSize) 
    {
        for (int i = (heapSize / 2)-1; i >= 0; --i)
        {
            minHeapify(a, i,heapSize-1);
        }
    }

    int findmax(int *nums,int m,int n,int d)
    {
        int s = 0;
        for(int x=m;x>0;--x)
        {
            int sum = 0;
            int* heap = new int[x];
            for (int i = 0; i < x; ++i)
            {
                heap[i] = nums[i];
                sum += heap[i];
            }
            build(heap, x);
            sum = sum - x * d;
            int f = x-1;
            for (int j = x; j < n; ++j)
            {
                if (nums[j] > heap[0])
                {
                    int t = heap[0];
                    heap[0] = nums[j];
                    build(heap, x);
                    sum = max(sum, sum-t+nums[j]-(j-f)*d);
                    f = j;
                }
            }
            s = max(sum, max(s, 0));
        }

        return s;
    }
    

int main()
{
   
    int n, m,d;
    
    readint(n); readint(m); readint(d);
    int* nums = new int[n];
    for (int i = 0; i < n; ++i)
    {
        readint(nums[i]);
    }
    
    cout << findmax(nums, m, n, d);
    return 0;
   
   
   

    
}