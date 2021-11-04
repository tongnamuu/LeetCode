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
    int solve(TreeNode* node, bool add) {
        if(!node) return 0;
        if(!node->left && !node->right && add) return node->val;
        return solve(node->left, 1) + solve(node->right, 0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return solve(root->left, 1) + solve(root->right, 0);
    }
};