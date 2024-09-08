#include <iostream>
#include<cstring>
using namespace std;

#define max(a, b) (a > b ? a : b)

//动态规划，dp[i][j]表示前i天看j部电影可获得的最大幸福值
//例如，第一天看与不看，第二天看与不看，最终有四种可能，其中有两种dp[2][1],此时取max
//最终所有取相同j的数据都会max一遍，时间复杂度为三次方
//将二维数组优化为两个一维数组last，cur
int main()
{
    int n, m, d;
    cin >> n >> m >> d;
    int* base = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> base[i];
    }

    int* last = new int[m - 1]; //大小为m-1，因为第m次总是单独计算，不必加入数组
    int* cur = new int[m - 1];
    memset(last, 0, m * sizeof(int));   //初始为第0天，看了0部电影，幸福度为0
    memset(cur, -2147483648, m * sizeof(int));  //每次都设置为-INT_MAX，可以直接max

    int res = 0;    //不看为0
    for (int i = 0; i < n; i++) {   //每次考虑看或不看base[i]
        //考虑以base[i]为最后一次的幸福度是否最大，从j=0取到j=i且j<m-1，这包含了只看base[i]的情况
        for (int j = 0; j <= i && j < m - 1; j++) {   //目前最多看了min(m, i)次
            res = max(res, (last[j] + base[i] - d * (i + 1)));
        }
        //更新cur:本次不看,直接转移
        for (int j = 0; j <= i && j < m - 1; j++) {
            cur[j] = last[j];
        }
        //更新cur:本次看
        for (int j = 0; j <= i && j < m - 2; j++) {
            cur[j + 1] = max((last[j] + base[i]), cur[j + 1]);
        }
        //cur, last互换
        int* hold = cur;
        cur = last;
        last = hold;
        //重填充cur
        memset(cur, -2147483648, m * sizeof(int));  //每次都设置为-INT_MAX，可以直接max
    }

    cout << res;
   
    return 0;
}