#include <iostream>
using namespace std;

int main()
{
    int n, m, d;
    cin >> n >> m >> d;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = new int[m + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m && j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j];
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i - 1] - d * (i - j));
        }
    }

    cout << (dp[n][m] > 0 ? dp[n][m] : 0);

    for (int i = 0; i <= n; i++)
        delete[] dp[i];
    delete[] dp;
    delete[] arr;

    return 0;
}