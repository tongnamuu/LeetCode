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
    int ans = -2147483647;
    int dist(TreeNode* root) {
        if (!root) return 0;
        int l = dist(root->left);
        int r = dist(root->right);
        ans = max({ans, l + r + root->val, l + root->val, r + root->val, root->val});
        return max({l + root->val, r + root->val, root->val});
    }
    int maxPathSum(TreeNode* root) {
        return max(dist(root), ans);
    }
};