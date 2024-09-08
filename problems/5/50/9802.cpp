#include <iostream>
#include <algorithm>
using namespace std;

const int DefaultSize = 8000000;
const int Increase = 100;

class MaxHeap {
    //最小堆继承了（最小）优先级队列
public:
    MaxHeap(int sz = DefaultSize);	//构造函数
    MaxHeap(long long arr[], int n);		//构造函数
    //～MaxHeap() { delete[] heap; }	//析构函数
    void OfProcess()
    {
        maxHeapSize += Increase;
        long long* temp = new long long[maxHeapSize];
        for (int i = 0; i != maxHeapSize - Increase; i++)
            temp[i] = heap[i];
        long long* d = heap;
        heap = temp;
        delete[] d;
    }
    bool Insert(const long long& x);			//插入
    bool Remove(long long& x);			//删除
    bool IsEmpty() const		//判堆空否
    {
        return  currentSize == 0;
    }
    bool IsFull() const		//判堆满否
    {
        return currentSize == maxHeapSize;
    }
    long long try_new(long long x)
    {
        return sum + x - heap[currentSize - 1];
    }
    long long& operator[](int index) { return heap[index - 1]; }
    void MakeEmpty() { currentSize = 0; }	//置空堆
    long long sum;
private:
    long long* heap;			//最小堆元素存储数组
    int currentSize;		//最小堆当前元素个数
    int maxHeapSize;	//最小堆最大容量
    void siftDown(int start, int m);	//调整算法
    void siftUp(int start);		          //调整算法
};


MaxHeap::MaxHeap(int sz) {
    maxHeapSize = (DefaultSize < sz) ?
        sz : DefaultSize;
    heap = new long long[maxHeapSize];  	//创建堆空间
    if (heap == NULL) {
        cerr << "堆存储分配失败！" << endl;  exit(1);
    }
    currentSize = 0;				//建立当前大小
    sum = 0;
};

MaxHeap::MaxHeap(long long arr[], int n) {
    maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
    heap = new long long[maxHeapSize];
    if (heap == NULL) {
        cerr << "堆存储分配失败！" << endl;  exit(1);
    }
    for (int i = 0; i < n; i++) heap[i] = arr[i];
    currentSize = n;	       //复制堆数组, 建立当前大小
    int currentPos = (currentSize - 2) / 2;
    //找最初调整位置:最后分支结点
    while (currentPos >= 0) {	    //逐步向上扩大堆
        siftDown(currentPos, currentSize - 1);
        //局部自上向下下滑调整
        currentPos--;
    }
    sum = 0;
};

void MaxHeap::siftDown(int start, int m) {
    //私有函数: 从结点start开始到m为止, 自上向下比较, 
    //如果子女的值小于父结点的值,  则关键码小的上浮, 
    //继续向下层比较, 将一个集合局部调整为最小堆。
    int i = start, j = 2 * i + 1;  	//j是i的左子女位置
    long long temp = heap[i];
    while (j <= m) {			//检查是否到最后位置
        if (j < m && heap[j] < heap[j + 1]) j++;
        //让j指向两子女中的大者
        if (temp >= heap[j]) break;	//大则不做调整
        else { heap[i] = heap[j];  i = j; j = 2 * j + 1; }
        //否则大者上移, i, j下降
    }
    heap[i] = temp;	      	//回放temp中暂存的元素
};

bool MaxHeap::Insert(const long long& x) {
    //公共函数: 将x插入到最小堆中
    if (currentSize == maxHeapSize) 	//堆满
    {
        //OfProcess();
        cout << "Heap Full" << endl;
        return false;
    }
    heap[currentSize] = x;  		//插入
    siftUp(currentSize);			//向上调整
    currentSize++;				//堆计数加1
    sum += x;
    return true;
};

void MaxHeap::siftUp(int start) {
    //私有函数: 从结点start开始到结点0为止, 自下向上
    //比较, 如果子女的值小于父结点的值, 则相互交换, 
    //这样将集合重新调整为最小堆。关键码比较符<=
    //在E中定义。
    int j = start, i = (j - 1) / 2;//i指向父节点   
    long long temp = heap[j];//所插入的值
    while (j > 0)
    {		//沿父结点路径向上直达根
        if (heap[i] >= temp) break;							//父结点值大, 不调整
        else { heap[j] = heap[i];  j = i;  i = (i - 1) / 2; }
        //父结点结点值小, 调整
    }
    heap[j] = temp;				//回送
};

bool MaxHeap::Remove(long long& x) {
    if (!currentSize) {		//堆空, 返回false
        cout << "Heap empty" << endl;
        return false;
    }
    x = heap[0];
    sum -= x;
    heap[0] = heap[currentSize - 1];
    currentSize--;
    siftDown(0, currentSize - 1);    	//自上向下调整为堆
    return true;			//返回最大元素
};

inline void readint(long long& a) {
    a = 0; char c; int sgn = 1;
    while ((c = getchar()) < 48) if (c == '-') sgn = -1;
    do a = a * 10 + (c ^ 48);
    while ((c = getchar()) > 47);
    a *= sgn;
}

int main()
{
    int n, m, d;
    cin >> n >> m >> d;
    MaxHeap heap(m);
    long long* happy = new long long[n];
    long long temp = 0;
    int last_index = 0;
    long long max_sum = 0;
    for (int i = 0; i != n; i++)
        cin >> happy[i];
    for (int i = 0; i != n; i++)
    {
        if (happy[i] > 0)
        {
            if (heap.IsFull())
            {
                temp = heap.sum;
                if (max_sum < heap.try_new(happy[i]) - (d * (i + 1)))
                {
                    heap.Remove(temp);
                    heap.Insert(happy[i]);
                    max_sum = heap.sum - (d * (i + 1));
                }
            }
            else
            {
                heap.Insert(happy[i]);
                max_sum = (max_sum > heap.sum - (d * (i + 1))) ? max_sum : heap.sum - (d * (i + 1));
                last_index = i;
            }
        }
        else
            continue;
    }
    cout << max_sum;
    return 0;
}