/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    int ans = 0;
    int d(TreeNode* root) {
        if (!root) return 0;
        int l = d(root->left);
        int r = d(root->right);
        ans = max(l + r, ans);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        d(root);
        return ans;
    }
};