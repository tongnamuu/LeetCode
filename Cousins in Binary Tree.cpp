/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    void go(TreeNode* node, int* d, int* p, int par) {
        if (!node) return;
        d[node->val] = d[par] + 1;
        p[node->val] = par;
        go(node->left, d, p, node->val);
        go(node->right, d, p, node->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int d[101] = {
            0,
        };
        int p[101] = {
            0,
        };
        go(root, d, p, root->val);
        return d[x] == d[y] && p[x] != p[y];
    }
};