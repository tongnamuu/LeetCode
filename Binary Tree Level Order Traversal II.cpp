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
    void solve(TreeNode* node, vector<vector<int>>& ans, int depth) {
        if (!node) return;
        if (ans.size() < depth + 1) {
            vector<int> temp;
            ans.push_back(temp);
        }
        ans[depth].push_back(node->val);
        solve(node->left, ans, depth + 1);
        solve(node->right, ans, depth + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root, ans, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};