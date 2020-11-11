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
    void solve(TreeNode* node, int min_value, int max_value) {
        if (!node) return;
        ans = max(ans, max(abs(node->val - min_value), abs(node->val - max_value)));
        min_value = min(min_value, node->val);
        max_value = max(max_value, node->val);
        solve(node->left, min_value, max_value);
        solve(node->right, min_value, max_value);
    }
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        solve(root, root->val, root->val);
        return ans;
    }
};
