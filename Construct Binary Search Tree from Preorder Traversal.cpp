/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *getTree(vector<int> &a, int s, int e)
    {
        TreeNode *node = new TreeNode(a[s]);
        if (s == e)
            return node;
        int l = s, r = e + 1;
        for (int i = s + 1; i <= e; ++i)
        {
            if (l == s && a[i] < node->val)
            {
                l = i;
            }
            if (r == e + 1 && a[i] > node->val)
            {
                r = i;
            }
        }
        if (l == s)
            node->left = nullptr;
        else
            node->left = getTree(a, l, r - 1);
        if (r == e + 1)
            node->right = nullptr;
        else
            node->right = getTree(a, r, e);
        return node;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return getTree(preorder, 0, preorder.size() - 1);
    }
};