#include <iostream>
using namespace std;
class Happiness 
{
    long long current;
    long long *Heap;
public:
Happiness(long long size);
void Heapify(long long start, long long end, bool is_siftdown);
void modifyHeap(long long x, bool is_insert);
int Top();
};
Happiness::Happiness(long long size) 
{
    current = 0;
    Heap=new long long[size];
}
void Happiness::Heapify(long long start, long long end, bool is_siftdown) 
{
    long long i = start;
    long long j = is_siftdown ? 2 * i + 1 : (i - 1) / 2;
    long long temp = Heap[i];
    if ((is_siftdown && j <= end) || (!is_siftdown && i > 0)) 
    {
            if (is_siftdown && j < end && Heap[j] > Heap[j+1]) 
            {
                j++;
            }
            if ((is_siftdown && temp <= Heap[j]) || (!is_siftdown && temp >= Heap[j])) 
            {
                return;
            } 
            else 
            {
                Heap[i] = Heap[j];
                i = j;
                j = is_siftdown ? 2 * i + 1 : (i - 1) / 2;
            }
        }
        Heap[i] = temp;
    }

void Happiness::modifyHeap(long long x, bool is_insert) {
 if (is_insert) 
        {
            Heap[current] = x;
            Heapify(current,0,false);
            current++;
        }   
        else 
        {
            Heap[0] = Heap[current - 1];
            current--;
            Heapify(0, this->current - 1,true);
        }
}

int Happiness::Top() {
 return Heap[0];
}

int calculateScore(long long n, long long m, long long d, long long a[]) 
{
    if (m == 0) 
    {
        return 0;
    }
    Happiness h(m);
    long long score = 0;
    long long sum = 0;
    long long size = 0;
    for (int i = 0; i < n; ++i)
    {
    int temp = a[i] - d * (i + 1);

    if (m > 1 && i >= 1 && a[i - 1] > 0) {
    h.modifyHeap(a[i - 1], true);
    size++;
    sum += a[i - 1];

    if (size == m) {
    sum = h.Top();
    h.modifyHeap(0, false);
    size--;
    }
    }
    if (sum + temp > score) 
    {
    score = sum + temp;
    }
    }

    return score;
 }

int main() 
{
    long long n, m, d;
    cin >> n >> m >> d;
    long long a[n];
    for (int i = 0; i < n; ++i) 
    {
    cin >> a[i];
    }
    long long score = calculateScore(n, m, d, a);
    cout << score;

    return 0;
}
