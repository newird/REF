#include<iostream>
#include<vector>
#include<deque>
#include<stack>
using namespace std;
int f(vector<int>& nums)
{
   int n = nums.size();
   stack<int> de;
   int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (de.empty() )
        {
            de.push(i);
            
        }
        else if (nums[i] >= nums[de.top()])
        {
            
            max = max > (nums[i] - nums[de.top()]) ? max : (nums[i] - nums[de.top()]);
        }
        else if (nums[i] < nums[de.top()])
        {
            de.pop();
            de.push(i);
        }
    }
    return max;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << f(a);
	return 0;
}