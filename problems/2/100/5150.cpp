#include<iostream>
#include<stack>

using namespace std;
int main()
{
	int n;
	cin>>n; 
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int helper = 0;
	int min=0;
	stack<int> st;
	for (int i = 0; i < n; i++)
	{
		if(st.empty())
		{
		    st.push(a[i]);
		    min=a[i];
	    }
		else if(a[i]>st.top())
		{
			st.push(a[i]);
		}
		else if (a[i]<st.top())
		{
			if(st.top()-min>helper)
			{
				helper=st.top()-min;
				
			}
			st.pop();
			i--;
		}

	}
	cout << helper;
}