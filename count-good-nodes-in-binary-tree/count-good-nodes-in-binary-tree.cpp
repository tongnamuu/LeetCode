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
    void solve(TreeNode* node, int prevMax, int& ans) {
        if(node->val >= prevMax) ++ans;
        int curMax = max(prevMax, node->val);
        if(node->left) solve(node->left, curMax, ans);
        if(node->right) solve(node->right, curMax, ans);

    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        solve(root, -2147483647, ans);
        return ans;
    }
};
