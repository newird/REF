#include<iostream>
using namespace std;

void siftDown(int* arr, int end, int start = 0)
{
    int i = start, j = 2 * i + 1;
    int temp = arr[i];
    while (j <= end)
    {
        if (j < end && arr[j] > arr[j + 1]) j++;
        if (temp <= arr[j]) break;
        else

        {
            arr[i] = arr[j];
            i = j;
            j = 2 * j + 1;
        }
    }
    arr[i] = temp;

}

long long calculateMaxHappiness(int numMovies, int numChances, int dailyDec, int* happiness)
{
    int cur = 0, chancesLeft = numChances - 1;
    long long curMax = 0, max = 0;
    int* heap;
    if (chancesLeft == 0) heap = NULL;
    else heap = new int[chancesLeft] {INT_MIN};

    for (; cur < numMovies; cur++)
    {
        if (cur > 0) curMax -= happiness[cur - 1];
        curMax += (happiness[cur] - dailyDec);
        if (numChances != 1)
        {
            if (chancesLeft > 0 && cur >= 1 && happiness[cur - 1] > 0)
            {
                curMax += happiness[cur - 1];
                chancesLeft--;
                heap[0] = happiness[cur - 1];
                siftDown(heap, numChances - 2);
            }
            else if (chancesLeft == 0 && cur >= 1 && happiness[cur - 1] > heap[0])
            {
                curMax += (happiness[cur - 1] - heap[0]);
                heap[0] = happiness[cur - 1];
                siftDown(heap, numChances - 2);
            }
        }
        max = max >= curMax ? max : curMax;
    }
    delete[] heap;
    return max;

}

int main()
{
    int numMovies, numChances, dailyDec;
    cin >> numMovies >> numChances >> dailyDec;

    int* happiness = new int[numMovies];
    for (int i = 0; i < numMovies; i++)
        cin >> happiness[i];

    cout << calculateMaxHappiness(numMovies, numChances, dailyDec, happiness);

    delete[] happiness;
    return 0;

}
