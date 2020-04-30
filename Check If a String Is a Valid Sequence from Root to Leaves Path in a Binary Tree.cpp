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
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }
    bool go(TreeNode* root, const vector<int>& a, int index) {
        if (!root) return index >= a.size();
        if (root->val != a[index]) return false;
        if (index == a.size() - 1) return isLeaf(root);
        return go(root->left, a, index + 1) | go(root->right, a, index + 1);
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return go(root, arr, 0);
    }
};