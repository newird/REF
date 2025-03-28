## 1. 看优质电影，获幸福人生



### 题目描述

​	最近小蓝鲸发现学校附近新开了一个电影院，在未来的 $n$ 天里，每天都会放映一部新电影。但是小蓝鲸并不是对所有的电影都很感兴趣，对于第 $i \ (1 \le i \le n)$ 部电影，小蓝鲸观看后会收获 $a_i$ 的幸福值。

​	然而，小蓝鲸不去电影院的时间越长，观看下一部电影时，幸福值下降的就越多。下降的幸福值等于 $d \times gap$，其中 $d$ 是一个**已知**的下降参数，而 $gap$ 是距离上一次去电影院的天数。同时，小蓝鲸在第 $0$ 天还去了另外一家电影院。

​	举个栗子，如果 $d = 2$ 且 $a = [3,2,5,4,6]$，如果小蓝鲸看了第 $1$ 天和第 $3$ 的电影，对于第 $1$ 天来说，$gap = 1 - 0 = 1$，对于第 $3$ 天来说，$gap = 3 - 1 = 2$，所以总的幸福值为 $a_1 - d \times 1 + a_3 - d \times 2 = 3 - 2 + 5 - 4 = 2 $。

​	可惜的是，小蓝鲸最多只有 $m$ 次去电影院的机会，请你帮助它算一算，它最多可以收获多少幸福值？



### 输入

输入包含两行

- 第一行包含三个整数 $n, m, d \ (1 \le n \le 2 \times 10^5, 1 \le m \le n, 1 \le d \le 10^9)$
- 第二行包含 $n$ 个整数 $a_1, a_2, ..., a_n \ (-10^9 \le a_i \le 10^9)$，表示观看每一部电影后的幸福值 



### 输出

- 输出包含一个整数，表示小蓝鲸最多可以收获的幸福值



### 样例1

- 输入

```
6 6 6
-82 45 1 -77 39 11
```

- 输出

```
60
```



### 样例2

- 输入

```
4 3 2
1 1 1 1
```

- 输出

```
0
```



### 解释

- 对于样例1，最优的选择是看第 $2,3,5,6$ 天的电影，总的幸福值为 $45 - 6 \times 2 + 1 - 6 \times 1 + 39 - 6 \times 2 + 11 - 6 \times 1 = 60$

- 对于样例2，最优的选择是不看电影