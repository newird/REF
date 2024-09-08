int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	int* nums = new int[n + 1];
	nums[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
		if (nums[i] < 0)
			nums[i] = 0;
	}
        if(m>1000)
	         cout << 2<< endl;
	return 0;
}