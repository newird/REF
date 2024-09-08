#include <iostream>
using namespace std;
class Happiness {
    int current;
    int *Heap;
public:
Happiness(int size);
void Heapify(int start, int end, bool is_siftdown);
void modifyHeap(int x, bool is_insert);
int Top();
};
Happiness::Happiness(int size) 
{
    current = 0;
    Heap=new int[size];
}
void Happiness::Heapify(int start, int end, bool is_siftdown) 
{
    int i = start;
    int j = is_siftdown ? 2 * i + 1 : (i - 1) / 2;
    int temp = Heap[i];
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

void Happiness::modifyHeap(int x, bool is_insert) {
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

int calculateScore(int n, int m, int d, int a[]) 
{
if (m == 0) 
{
    return 0;
}
Happiness h(m);
int score = 0;
int sum = 0;
int size = 0;
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

int main() {
int n, m, d;
cin >> n >> m >> d;
int a[n];
for (int i = 0; i < n; ++i) 
{
cin >> a[i];
}
int score = calculateScore(n, m, d, a);
cout << score;

return 0;
}
