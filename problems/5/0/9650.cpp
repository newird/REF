#include <iostream>
#include <vector>
using namespace std;

int FUNC(int n, int m, int d);

void heapMax(int* a, int i, int n)
{
    int j = i, kiri = i * 2 + 1, kanan = i * 2 + 2;
    if (kiri < n && a[j] < a[kiri])
    {
        j = kiri;
    }
    if (kanan < n && a[j] < a[kanan])
    {
        j = kanan;
    }
    if (j != i)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        heapMax(a, j, n);
    }
}

void buildmaxHeap(int* a, int n) //bikin heap dari maxheap dulu
{
    for (int i = n / 2 - 1; i >= 0;i--)
    {
        heapMax(a, i, n);
    }
}

int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	cout << FUNC(n, m, d);
	return 0;
}

int FUNC(int n, int m, int d)
{
    int* a = new int[n];
    int* b = new int[n];
    int index = 0;
	for (int i = 0;i < n ;i++) 
	{
		cin >> a[i];
        a[i] = a[i] - d * (i + 1);
        b[i] = a[i];
	}
    buildmaxHeap(b, n); //membuat heap 
    for (int i = 0; i < m - 1; i++) //cari nilai max dari ke k
    {
        int temp = b[0];
        b[0] = b[n - 1];
        b[n - 1] = temp;
        n--;
        heapMax(b, 0, n);
    }

    int max = b[0];
    int result = b[0];
    for (int i = 1; i < n + 1;i++)
    {
        if (a[i] > max)
        {
            result += a[i];
            max = a[i];
        }
    }
    return result;

}