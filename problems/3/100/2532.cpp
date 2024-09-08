#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int max = n > m ? n : m;
    int* p1 = new int[max];
    int* p2 = new int[max];
    if (p1 == NULL || p2 == NULL)
        cerr << "空间不足！" << endl;
    for (int i = 0; i < max ; i++)
    {
        p1[i] = p2[i] = 0;
    }
   
    int* result = new int[max + 1];
    for (int i = 0; i < max + 1; i++)
        result[i] = 0;

    for (int i = 0; i < n; i++)
    
        cin >> p1[i];
    for (int i = 0; i < m; i++)
        cin >> p2[i];

    
    for (int i = 0 ,cf = 0; i < max; i++)
    {   
        int sum = p1[i] + p2[i]+cf;
       
        result[i] = sum % 10 ;
        cf = sum / 10;
        if (i == max-1 && cf == 1)
            result[max] = 1;
    }
    if (result[max] != 0)
        cout << result[max];
    for (int i = max-1; i >= 0; i--)
    {
        cout << result[i];
    }
    delete[]p1;
    delete[] p2;
    delete [] result;
    return 0;
}

