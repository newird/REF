#include <limits.h>
#include <iostream>
using namespace std;

int happy(long long* arr, long long n, long long m, long long d, long long times, long long ans, long long idx, long long preidx)
{
    if (times == m || idx >= n) return ans;

    long long maxAns = ans;  // Initialize maxAns with the current ans.
    for (long long i = idx + 1; i < n; i++)
    {
        if (arr[i] > 0)
        {
            long long new_ans = ans + arr[i] - (i - preidx) * d;
            long long option1 = happy(arr, n, m, d, times, new_ans, i, preidx);  // Recursive call with updated ans.
            long long option2 = happy(arr, n, m, d, times + 1, new_ans, i, i);   // Recursive call with updated ans and preidx.
            maxAns = max(maxAns, max(option1, option2));  // Update maxAns with the maximum value among option1 and option2.
        }
    }

    return maxAns;
}

int main()
{
    long long n;
    long long m;
    long long b;
    cin >> n >> m >> b; // Input format changed to match the given input example.
    long long res;
    long long tmp;
    long long* arr = new long long[n];
    for (long long i = 0; i < n; ++i)
    {
        cin >> tmp;
        arr[i] = tmp;
    }
    res = happy(arr, n, m, b, 0, 0, -1, -1); // Initialize preidx with -1 to handle the first element.
    cout << res << endl;
    delete[] arr; // Don't forget to free the dynamically allocated memory.
    return 0;
}
