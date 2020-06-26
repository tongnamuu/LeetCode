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
    void solve(TreeNode* root, int val, int& ans) {
        if (!root->right && !root->left) {
            ans += (10 * val + root->val);
        }
        if (root->left) {
            solve(root->left, 10 * val + root->val, ans);
        }
        if (root->right) {
            solve(root->right, 10 * val + root->val, ans);
        }
    }
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        solve(root, 0, ans);
        return ans;
    }
};