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
    int ans = 0;
    void go(TreeNode* node, int& r) {
        if (!node) return;
        go(node->left, r);
        r--;
        if (r == 0) ans = node->val;
        go(node->right, r);
    }
    int kthSmallest(TreeNode* root, int k) {
        go(root, k);
        return ans;
    }
};