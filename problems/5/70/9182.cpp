#include<iostream>
#include<string>
using namespace std;


class PriorityQueue
{
private:
	int* pArray;
	int m_length;
public:
	PriorityQueue(int N) {
		// 为后续根节点直接从1开始作准备
		pArray = new int[N + 1];
		m_length = 0;
	}
	int getMax()
	{
		return pArray[1];
	}
	int delMax() {
		// 大根堆第一个元素为最大
		int max = pArray[1];
		// 将第一个元素和最后一个元素交换,并使长度减一，即删除最大的元素
		swap(pArray[1], pArray[m_length--]);
		// 防止对象游离
		pArray[m_length + 1] = NULL;
		// 下沉恢复堆的有序性
		sink(1);
		// 返回最大的节点值
		return max;

	}

	void insert(int v) {
		// 将值v插入到pArray[1]位置处，所以这里用的前置++
		pArray[++m_length] = v;
		// 新加入的元素上浮
		swim(m_length);
	}

	// 判断是否为空
	bool isEmpty() {
		return m_length == 0;
	}

	int size() {
		return m_length;
	}

	// 向上浮
	void swim(int k) {
		// 判断最下层的叶子节点值如果大于其父节点则进入循环上浮
		while (k > 1 && pArray[k] > pArray[k / 2]) {
			// 交换父节点和子节点
			swap(pArray[k / 2], pArray[k]);
			// k数值减小继续向上浮
			k /= 2;
		}
	}

	// 向下沉
	void sink(int k) {
		while (2 * k <= m_length)
		{
			// 由于堆的性质父节点为k则其左子树为2*k即j
			int j = 2 * k;
			// 这里先比较左子树和右子树的大小，将最大的那个键记录下来再和父节点比较
			if (j < m_length && (pArray[j] < pArray[j + 1])) j++;
			// 和父节点比较如果父节点比最大的子节点还要大，则直接退出循环
			if (pArray[k] > pArray[j]) break;
			// 如果父节点比子节点小则交换
			swap(pArray[k], pArray[j]);
			// k值变大继续下沉
			k = j;
		}
	}
};

int nums[200003];
int dp[200003];
int main()
{
    int n, m, d,temp;
    cin >> n >> m >> d;
    dp[0] = 0;
    nums[0] = 0;
    int op = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> nums[i];
    }
	PriorityQueue q(m+10);
    for (int i = 1; i <= n; ++i)
    {
		dp[i] = dp[i - 1];
		if (q.size() < m && nums[i] > 0)
		{
			q.insert(-nums[i]);
			dp[i] += nums[i];
		}
		else if (q.size() == m && nums[i] > -q.getMax())
		{
			dp[i]+=q.delMax()+nums[i];
			q.insert(-nums[i]);
		}
    }
	int out = 0;
	for (int i = 1; i <= n; ++i)
	{
		out = max(out, dp[i] - i * d);
	}
	cout << out;
}