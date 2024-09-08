#ifndef MINHEAP_H
#define MINHEAP_H
#define DefaultSize 100
#include<iostream>
using namespace std;


template <class E>
class MinHeap 
{
    //最小堆继承了（最小）优先级队列
public:
    MinHeap(int sz = DefaultSize);	//构造函数
    MinHeap(E arr[], int n);		//构造函数
    ~MinHeap()
    {
        delete[] heap;    //析构函数
    }
    bool Insert(E& x);			//插入
    bool Remove(E& x);			//删除

    bool Insert(E x, bool (*cmp) (E a, E b));			//插入
    bool Remove(E& x, bool (*cmp) (E a, E b));			//删除

    bool IsEmpty() const		//判堆空否
    {
        return  currentSize == 0;
    }
    bool IsFull() const		//判堆满否
    {
        return currentSize == maxHeapSize;
    }
    void MakeEmpty()
    {
        currentSize = 0;    //置空堆
    }

    E* heap;			//最小堆元素存储数组
    int currentSize;		//最小堆当前元素个数
    int maxHeapSize;	//最小堆最大容量
    void siftDown(int start, int m);	//调整算法
    void siftUp(int start);		          //调整算法
    void siftDown(int start, int m, bool (*cmp) (E a, E b));	//调整算法
    void siftUp(int start, bool (*cmp) (E a, E b));		          //调整算法
};


#endif // MINHEAP_H


template <class E>
MinHeap<E>::MinHeap(int sz)
{
    maxHeapSize = (DefaultSize < sz) ?
        sz : DefaultSize;
    heap = new E[maxHeapSize];  	//创建堆空间
    if (heap == NULL)
    {
        cerr << "堆存储分配失败！" << endl;
        exit(1);
    }
    currentSize = 0;				//建立当前大小
};

template <class E>
MinHeap<E>::MinHeap(E arr[], int n)
{
    maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
    heap = new E[maxHeapSize];
    if (heap == NULL)
    {
        cerr << "堆存储分配失败！" << endl;
        exit(1);
    }
    for (int i = 0; i < n; i++) heap[i] = arr[i];
    currentSize = n;	       //复制堆数组, 建立当前大小
    int currentPos = (currentSize - 2) / 2;
    //找最初调整位置:最后分支结点
    while (currentPos >= 0)  	    //逐步向上扩大堆
    {
        siftDown(currentPos, currentSize - 1);
        //局部自上向下下滑调整
        currentPos--;
    }
};



template <class E>
void MinHeap<E>::siftDown(int start, int m)
{
    //私有函数: 从结点start开始到m为止, 自上向下比较,
    //如果子女的值小于父结点的值,  则关键码小的上浮,
    //继续向下层比较, 将一个集合局部调整为最小堆。
    int i = start, j = 2 * i + 1;  	//j是i的左子女位置
    E temp = heap[i];
    while (j <= m)  			//检查是否到最后位置
    {
        if (j < m && heap[j] > heap[j + 1]) j++;
        //让j指向两子女中的小者
        if (temp <= heap[j]) break;	//小则不做调整
        else
        {
            heap[i] = heap[j];
            i = j;
            j = 2 * j + 1;
        }
        //否则小者上移, i, j下降
    }
    heap[i] = temp;	      	//回放temp中暂存的元素
};



template <class E>
bool MinHeap<E>::Insert(E& x)
{
    //公共函数: 将x插入到最小堆中
    if (currentSize == maxHeapSize) 	//堆满
    {
        cerr << "Heap Full" << endl;
        return false;
    }
    heap[currentSize] = x;  		//插入
    siftUp(currentSize);			//向上调整
    currentSize++;				//堆计数加1
    return true;
};

template <class E>
void MinHeap<E>::siftUp(int start)
{
    //私有函数: 从结点start开始到结点0为止, 自下向上
    //比较, 如果子女的值小于父结点的值, 则相互交换,
    //这样将集合重新调整为最小堆。关键码比较符<=
    //在E中定义。
    int j = start, i = (j - 1) / 2;
    E temp = heap[j];
    while (j > 0)  		//沿父结点路径向上直达根
    {
        if (heap[i] <= temp) break;							//父结点值小, 不调整
        else
        {
            heap[j] = heap[i];
            j = i;
            i = (i - 1) / 2;
        }
        //父结点结点值大, 调整
    }
    heap[j] = temp;				//回送
};



template <class E>
bool MinHeap<E>::Remove(E& x)
{
    if (!currentSize)  		//堆空, 返回false
    {
        cout << "Heap empty" << endl;
        return false;
    }
    x = heap[0];
    heap[0] = heap[currentSize - 1];
    currentSize--;
    siftDown(0, currentSize - 1);    	//自上向下调整为堆
    return true;			//返回最小元素
};


/////////////////////////////////////////////////////////////////////////



template <class E>
void MinHeap<E>::siftDown(int start, int m, bool (*cmp) (E a, E b))
{
    //私有函数: 从结点start开始到m为止, 自上向下比较,
    //如果子女的值小于父结点的值,  则关键码小的上浮,
    //继续向下层比较, 将一个集合局部调整为最小堆。
    int i = start, j = 2 * i + 1;  	//j是i的左子女位置
    E temp = heap[i];
    while (j <= m)  			//检查是否到最后位置
    {
        if (j < m && cmp(heap[j + 1], heap[j])) j++;
        //让j指向两子女中的小者
        if (cmp(temp, heap[j])) break;	//小则不做调整
        else
        {
            heap[i] = heap[j];
            i = j;
            j = 2 * j + 1;
        }
        //否则小者上移, i, j下降
    }
    heap[i] = temp;	      	//回放temp中暂存的元素
};



template <class E>
bool MinHeap<E>::Insert(E x, bool (*cmp) (E a, E b))
{
    //公共函数: 将x插入到最小堆中
    if (currentSize == maxHeapSize) 	//堆满
    {
        cerr << "Heap Full" << endl;
        return false;
    }
    heap[currentSize] = x;  		//插入
    siftUp(currentSize, cmp);			//向上调整
    currentSize++;				//堆计数加1
    return true;
};

template <class E>
void MinHeap<E>::siftUp(int start, bool (*cmp) (E a, E b))
{
    //私有函数: 从结点start开始到结点0为止, 自下向上
    //比较, 如果子女的值小于父结点的值, 则相互交换,
    //这样将集合重新调整为最小堆。关键码比较符<=
    //在E中定义。
    int j = start, i = (j - 1) / 2;
    E temp = heap[j];
    while (j > 0)  		//沿父结点路径向上直达根
    {
        if (cmp(heap[i], temp))break;							//父结点值小, 不调整
        else
        {
            heap[j] = heap[i];
            j = i;
            i = (i - 1) / 2;
        }
        //父结点结点值大, 调整
    }
    heap[j] = temp;				//回送
};



template <class E>
bool MinHeap<E>::Remove(E& x, bool (*cmp) (E a, E b))
{
    if (!currentSize)  		//堆空, 返回false
    {
        cout << "Heap empty" << endl;
        return false;
    }
    x = heap[0];
    heap[0] = heap[currentSize - 1];
    currentSize--;
    siftDown(0, currentSize - 1, cmp);    	//自上向下调整为堆
    return true;			//返回最小元素
};
int main() {
    //思路：但凡有可能帮助的都要放进堆里，每次只需要不断更新result(比较加上和不开心值减少带来的差距，事实上
    //不开心值只取决于最后一次看电影的节点。-》动态调整

    long long int n, m, d;
    cin >> n >> m >> d;
    long long int* pre = new long long int[n];
    long long int sum = 0;
   
    for (long long int i = 0; i < n; i++) {
        cin >> pre[i];
       // puresum += pre[i];
    }
    MinHeap<long long int> a;
    //int back;//记录最后的节点数，
    long long int result=0;//
    for (int i = 0; i < n; i++) {
        if (pre[i] > a.heap[0] && a.currentSize == m) {
            long long int x = 0;
            a.Remove(x);
            sum -= x;
            sum += pre[i];
            a.Insert(pre[i]);
            // back = i+1;
            if (sum - d * (i + 1) > result)result = sum - d * (i + 1);

        }
        else if (pre[i] > 0 && a.currentSize < m) {//可以进行一次比较
            a.Insert(pre[i]);
            //back = i+1;
            sum += pre[i];
            if (sum - d * (i + 1) > result)result = sum - d * (i + 1);
        }
        
    }
    cout << result;

}

