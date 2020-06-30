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
    bool solve(TreeNode* root, int sum, int cur) {
        if (!root) return false;
        cur += root->val;
        if (!root->left && !root->right) return sum == cur;
        return solve(root->right, sum, cur) || solve(root->left, sum, cur);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return solve(root, sum, 0);
    }
};