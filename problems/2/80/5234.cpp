#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[n];
    int curr = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }
    int max = p[1] - p[0];
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i ; j < n;++j)
         {   curr = p[j] - p[i];
            if (curr > max)
                max = curr;
         }
    }
    if(max<=0)
        cout << "0" << endl;
    else
        cout << max<<endl;
    return 0;
}