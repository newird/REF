#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct datafilm
{
    int val;
    datafilm* next;
    datafilm(int x):val(x),next(NULL){}
};

TreeNode* create(bool see, int maxfilm, int day, int gap, datafilm* curr)
{//gap为一天不看的惩罚，punish为当前看电影的惩罚
    if (curr == NULL || maxfilm <= 0)
    {
        return NULL;
    }
    else
    {
        int value;
        if (see)
        {
            value = curr->val - day*gap;
            maxfilm -= 1;
            day=1;
        }
        else
        {
            value = 0;
            day+=1;
        }
        TreeNode* root = new TreeNode(value);
        root->left = create(false,maxfilm,day,gap,curr->next);
        root->right = create(true,maxfilm,day,gap, curr->next);
        return root;
    }
}

datafilm* create1(int n)
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
        first->next = create1(n - 1);
        return first;
    }
}

int maxhappy(TreeNode* root,int res)
{
    if (root == NULL)
    {
        return res;
    }
    else
    {
        res += root->val;
        int lefthappy, righthappy;
        lefthappy = maxhappy(root->left, res);
        righthappy = maxhappy(root->right, res);
        return (lefthappy >= righthappy) ? lefthappy : righthappy;
    }
}

int main()
{
    int n, m, gap, res;
    cin >> n >> m >> gap;
    datafilm* firstday = new datafilm(0);
    datafilm* secondday = create1(n);
    firstday->next = secondday;
    TreeNode* root = create(true, m+1, 0, gap, firstday);
    res = maxhappy(root,0);
    cout << res;
    return 0;
}