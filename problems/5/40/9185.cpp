#include <iostream>
using namespace std;

struct datafilm
{
    int val;
    datafilm* next;
    datafilm(int x) :val(x), next(NULL) {}
};

datafilm* create(int n)
{
    if (n <= 0)
    {
        return NULL;
    }
    else
    {
        int x;
        cin >> x;
        datafilm* first = new datafilm(x);
        first->next = create(n - 1);
        return first;
    }
}

int maxhappy(datafilm* data,int maxfilm,int gap,int day,int res)
{
    if (data == NULL)
    {
        return res;
    }
    else
    {
        int value = data->val - gap * day;
        int seevalue = maxhappy(data->next, maxfilm - 1, gap, 1, res + value);
        int skipvalue = maxhappy(data->next, maxfilm, gap, day + 1, res);
        return (seevalue >= skipvalue) ? seevalue : skipvalue;
    }

}

int main()
{
    int n, m, gap, res;
    cin >> n >> m >> gap;
    res = maxhappy(create(n),m,gap,1,0);
    cout << res;
    return 0;
}